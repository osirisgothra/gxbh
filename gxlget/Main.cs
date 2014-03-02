using System;
using System.Xml;


namespace gxlget
{
    class MainClass
    {
        public static void Main(string [] args)
		{
			try
			{
				XmlDocument gxdoc=new XmlDocument ();
				string docname;
				docname = args[0];
				gxdoc.Load(docname);
				bool foundgx =false;
				XmlNode gxnode = null;
				
				foreach (XmlNode n in gxdoc.ChildNodes)
				{
					if (n.Name == "gxbase")
					{
						gxnode = n;
						foundgx = true;
						break;
					}
				}
				
				if (foundgx)
				{
					// found the base, now to process the command
					if (gxnode.HasChildNodes)
					{
						string command=args[1];
						switch (command)
						{
							default:
								Console.WriteLine("Unknown Command: "+command);
								break;
						}
					}
					else
					{
						Console.WriteLine("Empty gxbase xml document, nothing to parse!");
					}
					
				}
				else
				{
					Console.WriteLine(docname + ": This is not a gxbase xml document");
				}
			
			
			
				
				
			}
			catch ( Exception pex )
			{
				Console.WriteLine("Error: " + pex.Message);				
			}
			
				
			
        }
    }
}
