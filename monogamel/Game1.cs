#region Using Statements
using System;

using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Storage;
using Microsoft.Xna.Framework.Input;

#endregion

namespace monogamel
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
		KeyboardState lastState;
		KeyboardState thisState;
		
		
        public Game1()
        {
            graphics=new GraphicsDeviceManager (this);
            Content.RootDirectory="Content";                
            graphics.IsFullScreen=true;        
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here
            base.Initialize();
                
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch=new SpriteBatch (GraphicsDevice);

            //TODO: use this.Content to load your game content here 
			
        }
		
		
        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
		{
			/*
             * // For Mobile devices, this logic will close the Game when the Back button is pressed
             * if ( GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed )			    
             * {
			 *     Exit();
             * }
             * // REMOVED: I do not have a working gamepad, no way to test it, so its disabled for now
			*/

			// Get Current State
			if (Keyboard.GetState().IsKeyDown(Keys.Escape))
				Exit();
				
            // TODO: Add your update logic here            
            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            graphics.GraphicsDevice.Clear(Color.CornflowerBlue);
        
            //TODO: Add your drawing code here
            
            base.Draw(gameTime);
        }
    }
}

