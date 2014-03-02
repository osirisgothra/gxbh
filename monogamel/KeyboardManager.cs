using System;
using MonoGame.Utilities;
using MonoGame.Framework.GamerServices;
using MonoGame.Framework.MonoLive;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Storage;
using Microsoft.Xna.Framework.Input;


namespace monogamel
{
    public class KeyboardManager
    {
		public delegate void KeyMgrEvent(KeyboardState then, KeyboardState now, Keys key);
		public delegate void StringEvent(string e);
		
		public KeyboardState LastState { get; private set; }
		public KeyboardState ThisState { get; private set; }
		private Game parent;
		
        public KeyboardManager(ref Game parentgame)
        {
			LastState = Keyboard.GetState();	
			parent = parentgame;
			
			
        }
		private bool _waspressedbefore(Keys k)
		{
			foreach ( Keys b in LastState.GetPressedKeys() )			
				if (b == k) return true;			
			return false;
		}  
		private bool _wasunpressedbefore(Keys k)
		{
			bool retval = !_waspressedbefore(k);
			return retval;
		}
		
		public void TickUpdate()
		{
			LastState=ThisState;
			ThisState=Keyboard.GetState();
			foreach ( Keys l in LastState.GetPressedKeys() )
			{				
				foreach ( Keys k in ThisState.GetPressedKeys() )
				{
					KeyPress(LastState,ThisState,k);
				}
			}
			
		}
		public event KeyMgrEvent KeyDown;
		public event KeyMgrEvent KeyUp;
		public event KeyMgrEvent KeyPress;
		public event StringEvent WordDiscerned;
		public event StringEvent LineDiscerned;
		
    }
}

