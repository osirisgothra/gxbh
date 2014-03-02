using System;
using Gtk;

namespace gxml
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Application.Init ();
			Builder builder = new Builder (null, "gxml.interfaces.MainWindow.ui", null);
			MainWindow win = new MainWindow (builder, builder.GetObject ("window1").Handle);
			win.Show ();
			Application.Run ();
		}
	}
}
