using System.IO;
using System;
using System.Xml;

namespace gxparse
{
            


	static class project
	{
	
		public const string name = "gxparse";
		public static Version ver = new Version(0,1,0,0);
		
	}
	
	class MainClass
	{
		public static void Out(string str,bool errstream=false)
		{
			if (errstream)			
				Console.Error.WriteLine (str);			
			else
				Console.WriteLine (str);
		
		}
		public static void Oute(string str) { Out (str,true); }
				
		
		public static void Main (string[] args)
		{
			try
			{
				if (args.Length == 0)
				{
					Out ( project.name + " You must specify a filename.",true);
				}			
				else
				{			
					XmlDocument thedoc = new XmlDocument();
					if (File.Exists (args[0]))
					{
						thedoc.Load (args[0]);
						// document loaded, proceed normally
						bool gxbfound = false;
						bool isxml = false;
						bool gxbmultiflag = false;
						foreach (XmlNode node in thedoc.ChildNodes)
						{
							switch (node.NodeType) 
							{
							case XmlNodeType.XmlDeclaration:
								{
									float xmlversion = 0.0F;
									try
									{
										xmlversion = Convert.ToSingle (node.Attributes["version"].ToString ());
									}
									catch (Exception ex)
									{
										Out ("Critical: xml PI does not include required attribute, version! Detail:" + ex.Message,true);
									}
								    if (xmlversion >= 1.0F) 
									     isxml = true;
									else							     
									    Out ("Critical: xml version is LESS than required version 1.0!",true);
								}				
								break;				
							case XmlNodeType.Element:
                                if (isxml)
                                {
								if (node.Name == "gxbase")
								{
									if (gxbfound)
									{
										gxbfound = false;
										gxbmultiflag = true;
									}
									else if (!gxbmultiflag)
									{
										gxbfound = true;
									}								
								}
                                }
                                else
                                    throw new InvalidOperationException();
                                                                                                    break;								
								
							case XmlNodeType.Comment:
								// ignore comments
								break;							
							default:
								Out ("Unexpected XML encountered: " + node.NodeType.ToString());
								break;
							}
						}
						
						
						
					}
					else
					{
						Out( project.name + ": File does not exist or is not loadable/readable:" + args[0]);
						
					}
				}
			}
			catch (Exception outer_ex)
			{
				Oute ("Unexpected Exception Caught: " + outer_ex.Message);										
			}            
		}
	
	}
    
}

            
               
