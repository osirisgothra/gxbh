using System;
using System.Text.RegularExpressions;
using System.Collections.Generic;

// disables warnings for unused variables
#pragma warning disable 168, 219, 169


namespace gxechohelper
{
    #region Utility Declarations
    /// <summary>
    /// Console color extended class that can parse strings, ints, etc
    /// </summary>
    public struct ConsoleColorEx
    {

        // to int
        ConsoleColorEx(int initcolor):this()
        {
            Color = (ConsoleColor)initcolor;
        }
        ConsoleColorEx(ConsoleColor initcolor):this()
        {
            Color = initcolor;
        }
        ConsoleColorEx(string parsecolor):this()
        {
            parsecolor = parsecolor.ToLower();
            if (parsecolor != "darkgray" && parsecolor != "black")
            {
                if (parsecolor.Contains("bright"))
                    parsecolor = parsecolor.Replace("bright", "");
                else
                    parsecolor = "dark" + parsecolor;
            }
            ConsoleColor parsedcolor = ConsoleColor.Gray;
            Enum.TryParse(parsecolor, true, out parsedcolor);
            Color = parsedcolor;
        }

        static public implicit operator int(ConsoleColorEx val)
        {
            return (int)val.Color;
        }
        static public implicit operator ConsoleColorEx(int val)
        {
            ConsoleColorEx retval = new ConsoleColorEx(val);
            return retval;
        }
        static public implicit operator ConsoleColorEx(string val)
        {
            return new ConsoleColorEx(val);
        }

        // from int
        static public implicit operator ConsoleColor(ConsoleColorEx val)
        {
            return val.Color;
        }

        public ConsoleColor Color
        {
            get;
            set;
        }


    }

    /// <summary>
    /// Colorizer
    /// Structure to handle colors based on user's selection for colorizing
    /// digits, alphas, and puntuation (symbols)
    /// </summary>
    public struct Colorizer
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="gxechohelper.Colorizer"/> struct.
        /// </summary>
        /// <param name='colorname'>
        /// Colorname can be any generic name like "red" or "green" or can contain
        /// the prefix "bright", so "brightred" is valid too. If no appropriate name
        /// is parsed, the defaults will be silver, darkgrey, and white.
        /// </param>
        public Colorizer(string colorname)
        {
            colorname = colorname.ToLower();
            bool isbright = colorname.Contains("bright");

            // bright colors have their dark counterparts as darker components
            // dark colors get dark-gray as their darker components
            if (isbright)
                Symbols = colorname.Replace("bright","");
            else
                Symbols = 8;
            Alpha = colorname;
            // bright colors have white as their brighter component
            // dark colros get their bright counterparts as brighter components
            if (isbright)
                Digit = "white";
            else
                Digit = "bright"+colorname;
        }
        public ConsoleColorEx Alpha;
        public ConsoleColorEx Digit;
        public ConsoleColorEx Symbols;

    }

    /// <summary>
    /// Color mode:
    /// Alpha/Digit/Symbol - Corrosponds to the values in <see cref="gxechohelper.Colorizer"/> struct Colorizer.
    /// Commit - Used internally by the ColorChunkManager only - using it elsewhere can or will cause exceptions!
    /// Ansi -  Identifies an ANSI Escape Sequence, flags the string as not to be touched by any attribute
    ///         Please note that some ansi escape sequences that are nonstandard may not parse in correctly, stick
    ///         with STANDARDIZED sequences only! See http://www.wikipedia.org/wiki/ansi_escape_seqences for details.
    /// Init -  Used by the chunkmanager to denote a default value, this means no color should be set and allows for
    ///         the program know that the object is in it's initial state and ready for data. It is also used by the
    ///         ChunkManager after a Clear(see below) mode is sent.
    /// Clear-  Used by the chunk manager to reset the internal buffers to "Init" and re-init the List to zero entries.
    /// 258-511 Reserved for Commands
    /// 4-254  Reserved for Hints
    /// 512+   Not Reserved, For Use by other Developers
    /// </summary>
    public enum ColorMode:int
    {
        Ansi = 0, Alpha = 1, Digit = 2, Symbol = 3, AlphaCap = 4, Commit = 255, Init = 256, Clear = 257
    }

    /// <summary>
    /// Color chunk, manages a chunk of text with a color mode attribute
    /// does not actually contain the color, but does give a hint about what
    /// color to use when writing the chunk.
    /// <description>
    ///    chunk - the string that contains to text to be written
    ///    mode  - the hint that tells what color to use
    ///    write - automated method that writes the text to screen (no color change)
    /// </description>
    /// <example>
    /// Use write like this:
    ///    ColorChunk mychunk = new ColorChunk();
    ///    mychunk.chunk = "This is some text";
    ///    // we dont have to set mode for write to work, and it doesnt affect write at all anyways
    ///    mychunk.write;
    ///    // you don't need to use ()'s because it is actually a property, returns the length if you want it
    ///    // in this example, however, we don't need it so it is not assigned but just dropped as is by default.
    /// </example>
    /// </summary>
    public struct ColorChunk
    {
        public string chunk;
        public ColorMode mode;
        public int write
        {
            get
            {
                MainClass.cout = chunk;
                return chunk.Length;
            }
        }

    }

    /// <summary>
    /// Color chunk manager.
    /// <description>
    ///    Manages a list of ColorChunk objects and links them with a
    ///    Colorizer object that contains the ConsoleColorEx values needed
    ///    for color switching. You can add chars, one at a time using
    ///    AddChar, telling the class which kinds of hints. Also this class
    ///    facilitates ColorMode to ConsoleColor conversion using the current
    ///    Colorizer to determine the final color for any given string in the
    ///    list.
    /// </description>
    /// </summary>
    public class ColorChunkManager
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="gxechohelper.ColorChunkManager"/> class.
        /// The colorizer is set to white (not brightwhite) when initialized this way.
        /// </summary>
        public ColorChunkManager()
        {
            ChunkColorizer = new Colorizer("white");
            curchunk = "";
            curmode = ColorMode.Init;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="gxechohelper.ColorChunkManager"/> class.
        /// </summary>
        /// <param name='color'>
        /// Color to use, can be any regular color name accepted by class <see cref="gxechohelper.ConsoleColorEx"/>. ConsoleColorEx.
        /// </param>
        public ColorChunkManager(string color)
        {
            ChunkColorizer = new Colorizer(color);
            curchunk = "";
            curmode = ColorMode.Init;
        }

        public Colorizer ChunkColorizer { get; set; }
        public List<ColorChunk> Chunks = new List<ColorChunk>();
        public int Length { get { return Chunks.Count; } }
        public ColorChunk this [int indexer] {get{ return Chunks [indexer];}}

        /// <summary>
        /// Adds the char to the current chunk cache -- note: to use the chunks you've added here you must lastly call
        /// the Flush() function to ensure all chunks are in the list, otherwise you could have an incomplete list.
        /// </summary>
        /// <param name='c'>
        /// Character to add to the current or next chunk, the manager will determine if a new chunk is to be created
        /// </param>
        /// <param name='newmode'>
        /// The ColorMode hint to associate with this character when adding it to the chunklist cache. If it is different
        /// than the current cache's mode, the current chunk cache will be Flush()ed and the character will be placed at
        /// the start of the next string in the newly created chunk cache for that hint.
        /// </param>
        public void AddChar(char c, ColorMode newmode)
        {
            if (curmode != newmode)
            {
                if (curchunk.Length != 0)
                {
                    ColorChunk newchunk = new ColorChunk();
                    newchunk.chunk = curchunk;
                    newchunk.mode = curmode;
                    Chunks.Add(newchunk);
                }

                // never actually set the new mode to commit
                if (newmode != ColorMode.Commit)
                {
                    curmode = newmode;
                    curchunk = "" + c;
                }
                else
                {
                    // whe commiting, the new mode reverts to the default
                    // and the chunk cache is cleared
                    curmode = ColorMode.Alpha;
                    curchunk = "";
                }
            }
            else
            {
                curchunk += c;
            }

        }

        /// <summary>
        /// Flush the current chunk cache to the list, ensures all data is in the list. Does not flush when cache is empty.
        /// </summary>/
        public void Flush()
        {
            if (curchunk.Length > 0)
                Commit();
        }

        /// <summary>
        /// INTERNAL: commits the cache w/o checking
        /// </summary>
        private void Commit()
        {
            if (curmode == ColorMode.Commit)
                throw new InvalidOperationException("Commit is RESERVED for the commit function only!");
            AddChar('\0',ColorMode.Commit);
        }

        private string curchunk;
        private ColorMode curmode;

        public ConsoleColor ChunkToColor(ColorChunk item)
        {
            switch (item.mode)
            {
                // at this time, caps are white
                case ColorMode.AlphaCap:
                    return ConsoleColor.White;
                case ColorMode.Alpha:
                    return ChunkColorizer.Alpha.Color;
                case ColorMode.Digit:
                    return ChunkColorizer.Digit.Color;
                case ColorMode.Symbol:
                    return ChunkColorizer.Symbols.Color;
                default:
                    throw new NotSupportedException("You must handle this item's mode yourself, only Digit/Alpha/Symbol modes are allowed. The "+item.ToString()+" mode Can Not Be Translated Automatically!");

            }
        }


    }


    #endregion

    class MainClass
    {

        /// <summary>
        /// The color of the console at startup, this must remain readonly to ensure
        /// ansi escape sequences are written using the default color.
        /// </summary>
        public static readonly ConsoleColor InitConsoleColor = Console.ForegroundColor;

        #region Boilerplate Code
        #region Std Handlers

        public static string lastwritten = "";
        public static string lastread = "";
        public static int same_calls = 0;

        public enum StreamID
        {
            none = 0,
            stdout, stderr, stdin
        }
        public static StreamID laststream = StreamID.none;

        /// <summary>
        /// Writes output to stdout
        /// The extra code (that seems pointless) is there to detect consecutive calls so you can write code like this
        /// cerr = cout = item
        /// and only have one stream (err) be output, in case of dual stream writing.
        /// also, checks for consecutive call count and resets after the set has been reached (>1)
        /// This is done so a cerr/cout pair can be written, and if the next call to cerr happens to be the same thing, but
        /// independant (ie "Encountered another bad spot on the disk") then the message WILL be displayed as long as it is
        /// not part of a cout/cerr pair call, and call count will be reset so the next call to cout with the same thing will
        /// be ok, but the next call to cerr would NOT print anything (however, a consecutive call to cerr _would_)
        /// Also, the commented-out string (debugging) instructions, keep them, they are there in case of future problems
        /// or situations that may arise.
        /// </summary>
        /// <value>
        /// cout (string) writes assigned text to /dev/stdout (whatever pipe is attached)
        /// </value>
        public static string cout
        {
            set
            {
                /*
                Console.ForegroundColor = (ConsoleColor)8;
                Console.WriteLine("------------------------------------------------------------------------------------");
                Console.ForegroundColor = (ConsoleColor)7;

                string val = value;
                int samecalls = same_calls;
*/
                if (lastwritten == value && laststream == StreamID.stderr && same_calls < 1)
                    same_calls++;
                else
                {
                    Console.WriteLine(value);
                    same_calls = 0;
                }
                /* // uncomment this to debug display issues
                 Console.ForegroundColor = (ConsoleColor) 8;
                 Console.WriteLine("call: cout--value={0}, calls={1}, laststring={2} laststream={3}",val.Substring(1,8),samecalls,lastwritten.Length>=8?lastwritten.Substring(0,8):lastwritten,laststream.ToString());
                 Console.ForegroundColor = (ConsoleColor)7;
                */
                lastwritten = value;
                laststream = StreamID.stdout;

            }
        }

        /// <summary>
        /// Writes output to stderr
        /// Please read the annotation for cout, the same applies here. Pairs may be inverted (cout=cerr=value / cerr=cout=value)
        /// </summary>
        /// <value>
        /// cerr (string) writes assigned text to /dev/stderr (whatever pipe is attached)
        /// this is usually used to display error messages and guarentees the user is notified, at least more so
        /// than the sister stream, stdout, which often times gets redirected to /dev/null, although please note
        /// that so can stderr--if that is the case, you will not see anything. Remember to use logging for critical
        /// messages that the user needs to know about, and for urgent messages use dialog boxes or write to /dev/ttyX
        /// if possible, when VERY critical.
        /// </value>
        public static string cerr
        {
            set
            {
                /*
                Console.ForegroundColor = (ConsoleColor)8;
                Console.WriteLine("------------------------------------------------------------------------------------");
                Console.ForegroundColor = (ConsoleColor)7;
                string val = value;
                int samecalls = same_calls;
                 */
                if (lastwritten == value && laststream == StreamID.stdout && same_calls < 1)
                    same_calls++;
                else
                {
                    Console.WriteLine(value);
                    same_calls = 0;
                }
                /*
                Console.ForegroundColor = (ConsoleColor)8;
                Console.WriteLine("call: cerr--value={0}, calls={1}, laststring={2} laststream={3}",val.Substring(1,8),samecalls,lastwritten.Length>=8?lastwritten.Substring(0,8):lastwritten,laststream.ToString());
                Console.ForegroundColor = (ConsoleColor)7;
                */
                lastwritten = value;
                laststream=StreamID.stderr;

            }
        }
        /// <summary>
        /// Gets the input from the stdin device, usually the keyboard or the pipe connection of calling program.
        /// If you MUST have user input and are in a GUI, consider using a dialog box instead, or interface with
        /// a /dev/tty if user feedback is imperitive (such as cerr)        ///
        /// </summary>
        /// <value>
        /// cin (string) value, copy of the string data inputted by the stdin or connected pipe.
        /// </value>
        public static string cin
        {
            get
            {
                lastread = Console.ReadLine();
                laststream = StreamID.stdin;
                return lastread;
            }
        }

        #endregion
        /// <summary>
        /// The entry point of the program, where the program control starts and ends.
        /// </summary>
        /// <param name='args'>
        /// The command-line arguments.
        /// </param>
        public static int Main(string[] args)
        {

            if (args.Length == 1 && args [0] == "--help")
            {
                try{

                    cout = new System.IO.StreamReader(typeof(MainClass).Assembly.GetManifestResourceStream( typeof(MainClass).Assembly.GetManifestResourceNames()[0])).ReadToEnd();
                }
                catch (Exception pex)
                {
                    cerr = 
                    cout = "Fatal: internal resource help couldn't be displayed. You're probably out of memory."+
                            "The Exception Caught was: " + pex.Message;


                }

            
             
            }
            else if (args.Length != 3)
            {
                cerr =
                cout = "Need exactly three arguments, command, subcommand and string.";
            }
            else
            {
                switch (args [0])
                {
                    case "colorize":
                        return ColorizeCout(args[1],args[2]);
                    default:
                        cerr = cout = "Unknown command: " + args[0];
                        break;
                }
            }
            return 1;  // error if made it here
        }
        #endregion

        #region Meat Functions
        /// <summary>
        /// Colorizes text and writes it to stdout (buffered)
        /// </summary>
        /// <returns>
        /// 0=ok 1=exception caught 2=other error(reserved)
        /// </returns>
        /// <param name='color'>
        /// Color base name, can be any generic name like "red" or "brightgreen"
        /// </param>
        /// <param name='str'>
        /// String to print in color
        /// </param>
        public static int ColorizeCout(string color, string str)
        {
            try
            {
                /// do initial character conversions, at this time the
                /// only escapes supported are: \a \b \t \n \v \f \r

                str = str.Replace(@"\a",new string((char)7,1));  // BELL (beep)
                str = str.Replace(@"\b",new string((char)8,1));  // BACKSPACE (go one step backwards)
                str = str.Replace(@"\t",new string((char)9,1));  // TAB (go to next tabstop)
                str = str.Replace(@"\n",new string((char)10,1)); // NEWLINE (unix text default)***
                str = str.Replace(@"\v",new string((char)11,1)); // VTAB (move to next vertical tabstop*)
                str = str.Replace(@"\f",new string((char)12,1)); // FORMFEED (move to next page**)
                str = str.Replace(@"\r",new string((char)13,1)); // CARRIAGE RETURN (go to first column)***
                str = str.Replace(@"\e",new string((char)27,1)); // ESCAPE (go to first column)***

                // printing-char codes (visible characters)
                str = str.Replace(@"\?",@"?");
                str = str.Replace(@"\\",@"\");

                // the \xdd item, needs parsing
                while(true)
                {
                    Match match = Regex.Match(str,@"\\x[a-fA-F0-9][a-fA-F0-9]",RegexOptions.ECMAScript|RegexOptions.Multiline);
                    if (match.Success == false)
                        break;
                    string valpart = "0x"+match.Value.Substring(2);
                    int intpart = Convert.ToInt32(valpart,16);
                    char newval = Convert.ToChar(intpart);
                    str = str.Replace(match.Value, new String(newval,1));
                }



                ColorChunkManager manager = new ColorChunkManager(color);

                bool inansiseq = false;
                ColorMode lastenteredmode = ColorMode.Init;
                for (int i=0; i < str.Length; i++)
                {

                    Char cur = str [i];
                    Char next = (i + 1 < str.Length) ? str [i + 1] : '\0';
                    // ansi escapes take priority since they can contain a combination
                    // of letters, numbers and symbols -- which wont work if they get
                    // colorized!
                    if ((cur == 27 && next == '[') || inansiseq)
                    {
                        inansiseq = !Char.IsLetter(cur);
                        manager.AddChar(cur, ColorMode.Ansi);
                        lastenteredmode=ColorMode.Ansi;
                    }
                    else if ((Char.IsUpper(cur) && Char.IsUpper(next)) ||
                             (Char.IsUpper(cur) && lastenteredmode == ColorMode.AlphaCap)
                             )
                    {
                        manager.AddChar(cur,ColorMode.AlphaCap);
                        lastenteredmode=ColorMode.AlphaCap;
                    }
                    else if (Char.IsPunctuation(cur))
                    {
                        manager.AddChar(cur, ColorMode.Symbol);
                        lastenteredmode=ColorMode.Symbol;
                    }
                    else if (Char.IsDigit(cur))
                    {
                        manager.AddChar(cur, ColorMode.Digit);
                        lastenteredmode=ColorMode.Digit;
                    }
                    else // assume character for others
                    {
                        manager.AddChar(cur, ColorMode.Alpha);
                        lastenteredmode=ColorMode.Alpha;
                    }

                }
                // This deals with the possibility of a broken ansi sequence at
                // the end of the string, in case we will close it with the 'm'
                // which is the most common code that selects color attributes.
                if (inansiseq)
                    manager.AddChar('m', ColorMode.Ansi);
                // now that the chunks are built, ensure that they are committed to
                // the internal list within the manager (and not floating in the cache!)
                manager.Flush();
                // now ready to write to the screen, finally!
                foreach (ColorChunk chunk in manager.Chunks)
                {
                    if (chunk.mode != ColorMode.Ansi)
                        Console.ForegroundColor = manager.ChunkToColor(chunk);
                    else
                        Console.ForegroundColor = InitConsoleColor;
                    Console.Write(chunk.chunk);
                }
            }
            catch (Exception pex)
            {
                cerr = cout = "Error (exception): " + pex.Message + "\n" +
                    "source: " + pex.Source + "\n" +
                    "ixm/ixs*: " + (pex.InnerException != null ? pex.InnerException.Message + "/" + pex.InnerException.Source : "none/none") + "\n" +
                    "(*above: inner-exception message / source, if any) -- final result code=1";
                return 1;
            }
            return 0;


        }
        #endregion
    }
}