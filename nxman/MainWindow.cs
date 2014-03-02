using System.Collections.Specialized;
using System.Collections.Generic;
using WebKit;
using System;
using System.Diagnostics;
using System.IO;
using gxlcommon;
using Gtk;

public partial class MainWindow: Gtk.Window
{    
    // forced list of man paths that are defined as standard in all distributions
    // of linux today (as of 2013). This list is used in conjunction with the
    // paths spat out by /usr/bin/manpaths (if any, if available). This prevents
    // disfunction on systems that do not have the binary /usr/bin/manpath.
    public const string altmanpaths = 
        "/usr/share/man:" + 
        "/usr/man:" + 
        "/usr/local/share/man:" +
        "/usr/local/man:" +
         "/var/cache/man";
    // example /usr/bin/manpath output (from my system ubuntustudio 13.10b1/i386)
    // [01]: osirisgothra@paradisim.tk ~ 1015 36 9:15 $ manpath
    // [02]: /usr/local/man:/usr/local/share/man:/usr/share/man
    // [03]: _
    // expected results (typical of above system)
    // this should be in the ballpark of what your system is, if not you may
    // let me know how i can improve it's accuracy.
    // folder                exist?      empty?      alt|dyn (dyn means from manpath)
    // ---------------------------------------------------------------------------------
    // /usr/share/man          X                       both
    // /usr/man                 
    // /usr/local/share/man
    // /usr/local/man
    // /var/cache/man
    // --(up-alt)(dn-dyn)--
    // /usr/local/man
    // /usr/local/share/man
    // /usr/share/man
    //

	TreeViewColumn filenameColumn = new TreeViewColumn();
	TreeViewColumn titleColumn = new TreeViewColumn();
	TreeStore mainstore = new Gtk.TreeStore(typeof(string),typeof(string));
	CellRendererText filenameColumn_Renderer = new CellRendererText();
	CellRendererText titleColumn_Renderer = new CellRendererText();
	TreeModelFilter mainstore_filter;
	bool ShowItems = false;
    private WebView wv;
	
    public MainWindow(): base (Gtk.WindowType.Toplevel)
    {
        Build();

        wv = new WebKit.WebView();

        wv.Editable = false;

        browbox.Add (wv);
        Gtk.Box.BoxChild w = ((Gtk.Box.BoxChild)browbox[wv]);
        w.Position =0 ;
        w.Exand = true;
        w.Fill = true;
        browbox.ShowAll();
        wv.NavigationRequested += delegate(object o, NavigationRequestedArgs args)
        {
            string uri = args.Request.Uri;
            uri.IsNormalized();
        };
        //wv.HoveringOverLink += (o, args) => new MessageDialog(this, DialogFlags.Modal, MessageType.Info, ButtonsType.Ok, args.Link).Show ();

		wv.LoadUri ("http://www.google.com");

		//TextTag redtag = new TextTag(null);
		//textview1.Buffer.TagTable.Add(redtag);
		//TextIter iter = textview1.Buffer.GetIterAtOffset(0);
		//redtag.ForegroundGdk = new Gdk.Color(255,0,0);
		//textview1.Buffer.InsertWithTags(ref iter, "My Red Text", redtag);				
		PrePopulateTree();
    }
	
	void PrePopulateTree ( )
    {		
        filenameColumn.Title = "Name";
        titleColumn.Title = "Title";
        treeview1.AppendColumn ( filenameColumn );
        treeview1.AppendColumn ( titleColumn );
        filenameColumn_Renderer = new CellRendererText ( );
        titleColumn_Renderer = new CellRendererText ( );
        filenameColumn.PackStart ( filenameColumn_Renderer , true );
        titleColumn.PackStart ( titleColumn_Renderer , true );
        filenameColumn.AddAttribute ( filenameColumn_Renderer , "text" , 0 );
        titleColumn.AddAttribute ( titleColumn_Renderer , "text" , 1 );
        TreeIter iter = mainstore.AppendValues ( System.Environment.GetEnvironmentVariable ( "HOSTNAME" ) );
		
        StringCollection manpaths = new StringCollection();
		
        try
        {
            System.Diagnostics.ProcessStartInfo startinfo = new System.Diagnostics.ProcessStartInfo ( "/usr/bin/manpath" );
            startinfo.RedirectStandardOutput = true;
            startinfo.UseShellExecute = false;				
            System.Diagnostics.Process proc = System.Diagnostics.Process.Start ( startinfo );				
            manpaths.AddRange (proc.StandardOutput.ReadToEnd ( ).Trim ().Split ( ':' ));

        } catch ( Exception ex )
        {	
            new MessageDialog ( null , DialogFlags.Modal , MessageType.Error , ButtonsType.Ok , ex.Message ).Show ( );
        } finally
        {
            // builtin paths, always to be used even if not in manpaths
            // they are standardized paths that all distros use
            if (manpaths == null)
                manpaths.AddRange ( altmanpaths.Trim ().Split (':'));
            else            
                foreach (string item in altmanpaths.Trim ().Split (':'))                
                    if (!manpaths.Contains (item))                    
                        manpaths.Add (item);
            // pre-remove entries that contain no entries or
            // that do not exist

            for (int i = manpaths.Count-1; i >= 0; i--)
            {
                string s = manpaths[i];
                System.Diagnostics.Debug.Write ("Manpath {0} - Check ",s);
                if (! Directory.Exists (s) || Directory.GetFileSystemEntries (s).Length < 1)
                {
                    manpaths.RemoveAt (i);
                    System.Diagnostics.Debug.Write ("REMOVED (not exist or empty)");
                }
                System.Diagnostics.Debug.WriteLine("");
            }


        }
		
		foreach ( string item in manpaths )
		{
			PopulateBranch(iter,item);			
		}				
		mainstore_filter = new TreeModelFilter(mainstore,mainstore.GetPath(iter));
		mainstore_filter.VisibleFunc = new TreeModelFilterVisibleFunc(FilterTree);
        treeview1.Model = mainstore_filter;

	}
	void PopulateBranch ( TreeIter root , string Path )
    {

        Path = Path.Trim ('\n','\r','\f',' ');
        TreeIter thisnode = mainstore.AppendValues (Path, System.IO.Path.GetDirectoryName(Path));
        //TreeIter thisnode = mainstore.AppendNode( root );

        if (Directory.Exists (Path))
        {

            string[] items = System.IO.Directory.GetFileSystemEntries(Path);

            
            foreach (string s in items)
            {
                mainstore.AppendValues (thisnode,s);
            }
        }            
   	}
	
	private bool FilterTree(Gtk.TreeModel model,Gtk.TreeIter iter)
	{
		return !( model.GetValue(iter,0).ToString().StartsWith(".") && ShowItems == false );		
	}
    
    protected void OnDeleteEvent(object sender,DeleteEventArgs a)
    {
        ExitProgram(sender,a);
        a.RetVal = true;
    }
	protected void ExitProgram(object sender, EventArgs e)
	{
		Application.Quit();		
	}
	
	protected void OnExitActionActivated(object sender, EventArgs e)
	{
		ExitProgram(sender,e);	
	}
	
	protected void OnShowHiddenActionToggled(object sender, EventArgs e)
	{
		ShowItems = ShowHiddenAction.Active;
		mainstore_filter.Refilter();
	}
}