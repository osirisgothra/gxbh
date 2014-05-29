using Gtk;
using System;
using System.Diagnostics;
using F = System.IO.File;
using D = System.IO.Directory;
using P = System.Diagnostics.Process;
using SI = System.Diagnostics.ProcessStartInfo;

namespace gxlcommon
{
    public static class file
    {
		/// <summary>
		/// Read text file, even if compressed with gzip
		/// </summary>
		/// <param name='filename'>
		/// File's name, must be a full or relative path to the current directory
		/// </param>
		/// <param name='readasis'>
		/// When false, attempt to unzip if the file's magic says that it is compressed,
		/// otherwise read normal.
		/// When true, always read normal, never check the magic.
		/// </param>
        public static string readfile(string filename,bool readasis=false)
		{	
			if ( readasis )
			{
				return System.IO.File.ReadAllText(filename);
			}
			else
			{
				string magic = getmagic(filename);
				if (magic.Contains("gzip"))					
				{
					System.IO.FileStream fs = new System.IO.FileStream(filename, System.IO.FileMode.Open, System.IO.FileAccess.Read, System.IO.FileShare.ReadWrite, 1024, true);
					
					System.IO.Compression.GZipStream gzstream = new System.IO.Compression.GZipStream(fs, System.IO.Compression.CompressionMode.Decompress,true);
					System.IO.StreamReader sr = new System.IO.StreamReader(gzstream,true);
					string retval = sr.ReadToEnd();
					sr.Close();					
					gzstream.Close();
					return retval;
				}
				else
					return "";
			}			
		}
		
		public static string getmagic(string filename)
		{
			if ( F.Exists(filename) )
			{
				bool failflag = false;				
				string magic_pre = commandtotext("file",out failflag, "-bN", filename);
				if (!failflag)
					return magic_pre.ToLower();
			}
			else
			{
				throw new System.IO.FileNotFoundException(filename);				
			}
			return "invalid";
		}
		
		
		public static string commandtotext(string command,out bool failedflag,params string [] args)
		{	
			string retval="";
			string errval="";
			string arg="";
			foreach ( string v in args )
			{
				if ( arg.Length > 0 )
					arg+=" ";
				if ( v.Contains(" ") )
					arg+="\"" + v + "\"";
				else
					arg+=v;
			}
			SI si=new SI (command , arg);
			si.UseShellExecute=false;
			si.RedirectStandardInput=true;
			si.RedirectStandardOutput=true;
			si.RedirectStandardError=true;
			try
			{
				Process newproc=new Process ();
				newproc.StartInfo=si;
				newproc.Start();
				
				retval=newproc.StandardOutput.ReadToEnd();
				errval=newproc.StandardError.ReadToEnd();
				failedflag=false;				
			}
			catch ( Exception ex )
			{
				new Gtk.MessageDialog (null , Gtk.DialogFlags.Modal , Gtk.MessageType.Error , Gtk.ButtonsType.Ok , ex.Message).Show();
				failedflag=true;
			}
			finally
			{
				// If command returns text solely in the error stream, we shall
				// consider it an error and display it's output to the user. 
				if (retval.Length == 0 && errval.Length != 0)
				{
					new Gtk.MessageDialog(null,Gtk.DialogFlags.Modal,Gtk.MessageType.Info,Gtk.ButtonsType.Ok, errval).Show();					
					failedflag = true;
				}
			}
			return retval;
						
		}
    }
	public static class MessageBox
	{
		public enum MessageBoxIcons
		{
			Error, Information, Question, Exclamation, None
		}
		public enum MessageBoxButtons
		{
			Ok, OkCancel, YesNoCancel, AbortRetryIgnore
		}
		public enum DialogResult
		{
			Ok, Cancel, Yes, No, Abort, Retry, Ignore
		}
		public static DialogResult Show( Gtk.Window parent, string message, string title, MessageBoxIcons iconstyle=MessageBoxIcons.Information, MessageBoxButtons buttons=MessageBoxButtons.Ok, bool modal=true)			
		{
			
			MessageType messagetype = MessageType.Info;
			
			Gtk.ButtonsType buttonstype = ButtonsType.Ok;
			DialogFlags dialogflags = DialogFlags.NoSeparator | DialogFlags.Modal;
			
			
			
			String fmtstring = message;
			
			
						
			
			
			
			switch(buttons)
			{
				case MessageBoxButtons.AbortRetryIgnore:
					break;
				case MessageBoxButtons.Ok:
					break;
				case MessageBoxButtons.OkCancel:
					break;
				case MessageBoxButtons.YesNoCancel:
					break;
				
				default:
					break;
			}
			
			
			
			Gtk.MessageDialog msgdlg = new Gtk.MessageDialog(parent,dialogflags,messagetype,buttonstype,fmtstring);
			
			msgdlg.Title = title;	
			
			return DialogResult.Ok;

		}
		
	}
}

