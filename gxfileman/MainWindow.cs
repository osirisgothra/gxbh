using System;
using Gtk;

public partial class MainWindow: Gtk.Window
{    
    public MainWindow(): base (Gtk.WindowType.Toplevel)
    {
        Build();
    }
    
    protected void OnDeleteEvent(object sender,DeleteEventArgs a)
    {
        Application.Quit();
        a.RetVal=true;
    }
	protected void OnFilechooserwidget1SelectionChanged(object sender, EventArgs e)
	{
		
	}	
	
	protected void OnFilechooserwidget1FileActivated(object sender, EventArgs e)
	{
		throw new System.NotImplementedException();
	}	
	
	protected void OnFilechooserwidget1UpdatePreview(object sender, EventArgs e)
	{
		throw new System.NotImplementedException();
	}	
	
	protected void OnFilechooserwidget1CurrentFolderChanged(object sender, EventArgs e)
	{
		throw new System.NotImplementedException();
	}	
	
	protected void OnFilechooserwidget1ConfirmOverwrite(object o, ConfirmOverwriteArgs args)
	{
		throw new System.NotImplementedException();
	}





}
