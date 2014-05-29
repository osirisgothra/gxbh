using System;
using Gtk;

namespace gxed
{
    class MainClass
    {
        public static void Main(string [] args)
        {
            Application.Init();
            MainWindow win=new MainWindow ();
            win.Show();
            Application.Run();
        }
    }
}
