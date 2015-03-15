using System;
using System.IO;
using System.Text.RegularExpressions;
using System.Collections.Generic;
/* 

 ManPage.cs
 
 Author:
      Gabriel T. Sharp <osirisgothra@hotmail.com>

 Copyright (c) 2013-2015 Paradisim Enterprises, LLC

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
*/

namespace nxman
{
    public class DocumentHF
    {
        public string Header { get; set; }
        public string Footer { get; set; }
    }

    public enum ElementType
    {
        Unknown=0,
        SectionHeading=1,
        SubHeading=2,
        Paragraph=3,
        HangingParagraph=4,
        NestedIndentStart=5,
        NestedIndentEnd=6,
        Italics=7,
        Comment=8
    }
    public enum IndentStyles
    {
        Normal, Hanging, Tagged
    }
    public struct TextFormat
    {
        public bool FontBold {get;set;}
        public bool FontUnderline { get; set; }
        public bool FontItalic {get;set;}
        public bool FontStrike {get;set;}
        public int FontSizePoints {get;set;}
        public bool Indented { get; set; }
        public int IndentedLines {get;set;}
        public bool EndIndent { get; set; }
        // cause style to apply to the next paragraph
        public IndentStyles IndentStyle { get;set;}
        public void InitElements ( bool B , bool U , bool I , bool K , int size , bool indent , IndentStyles style, int ilines)
        {
            this.FontBold=B;
            this.FontItalic=I;
            this.FontUnderline=U;
            this.FontStrike=K;
            this.FontSizePoints = size;
            this.Indented = indent;
            this.IndentStyle = style;
            this.IndentedLines = ilines;
        }
    }

    public struct TextFragment
    {
        public string Text { get; set; }
        public TextFormat Format {get; set;}
        public void InitElements( bool B , bool U , bool I , bool K , int size , bool indent , IndentStyles style, int ilines)
        {
            Format.FontBold=B;
            Format.FontItalic=I;
            Format.FontUnderline=U;
            Format.FontStrike=K;
            Format.FontSizePoints = size;
            Format.Indented = indent;
            Format.IndentStyle = style;
            Format.IndentedLines = ilines;

        }
    }

    public class ManPageHeadElements
    {
        public string Name	{ get; set; }	
        public string Section	{ get; set; }	
        public int SectionNumber
        {
            get
            {
                return Convert.ToInt32 ( Section );
            }
            set
            {					
                Section = value.ToString ( );
            }			
        }
        public DocumentHF Center { get; set; }
        public string LeftFooter { get; set; }

    }

    public class ManPage 
    {

        public ManPage ( string content )        
        {
            TextFormat CurrentFormat;
            // TODO: set CurrentFormat initially to user's preferred defaults
           
            CurrentFormat.InitElements (false,false,false,false,8,false,IndentStyles.Normal,0);





            string[] lines = content.Split('\n');
            foreach (string line in lines)
            {
                if (line.Trim().StartsWith("."))
                {
                }

            }
        }

        /// <summary>
        /// Gets the document's preamble attributes and textual data.
        /// </summary>
        /// <value>
        /// Gets the ManPageHeadElements object
        /// </value>
        public ManPageHeadElements Preamble { get; private set; }

        public List<TextFragment> Content = new List<TextFragment>();

    }
}

