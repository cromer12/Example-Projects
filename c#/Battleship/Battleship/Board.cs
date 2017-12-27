using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


/*
*Name: Cameron Cromer
*Date: 4/21/2016
*Project: board class 
*purpose: To hold and operate the parameters of the game boards
*/

namespace Battleship
{
    class Board
    {

       private int[,] playBoard = new int[10,10];       //the board
                
       public Board()                                  //contruct array
        {
            for (int x = 0; x < 10; x++)
            {
                for (int y = 0; y < 10; y++)
                {
                    playBoard[x, y] = 0;
                }
            }
        }

        public int setFive(int x, int y, int direction)               //sets Carrier's(6) Posistion
        {                                                              //directions only take 1-4;
            try
            {
                if (direction == 1)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x - 1, y] == 0 && playBoard[x - 2, y] == 0 && playBoard[x - 3, y] == 0 && playBoard[x - 4, y] == 0)
                    {

                        playBoard[x, y] = 6;
                        playBoard[x - 1, y] = 6;
                        playBoard[x - 2, y] = 6;
                        playBoard[x - 3, y] = 6;
                        playBoard[x - 4, y] = 6;
                        return 0;
                    }

                }
            }
            catch
            {       
              return 1;
            }

            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            try
            {
                if (direction == 2)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x, y + 1] == 0 && playBoard[x, y + 2] == 0 && playBoard[x, y + 3] == 0 && playBoard[x, y + 4] == 0)
                    {

                        playBoard[x, y] = 6;
                        playBoard[x, y + 1] = 6;
                        playBoard[x, y + 2] = 6;
                        playBoard[x, y + 3] = 6;
                        playBoard[x, y + 4] = 6;
                        return 0;
                    }

                }
            }
            catch
            {    
                return 1;
            }

            //////////////////////////////////////////////////////////////////////////////////////////////////////////

            try
            {
                if (direction == 3)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x + 1, y] == 0 && playBoard[x + 2, y] == 0 && playBoard[x + 3, y] == 0 && playBoard[x + 4, y] == 0)
                    {


                        playBoard[x, y] = 6;
                        playBoard[x + 1, y] = 6;
                        playBoard[x + 2, y] = 6;
                        playBoard[x + 3, y] = 6;
                        playBoard[x + 4, y] = 6;
                        return 0;
                    }
                }
            }
            catch
                {
                    
                return 1;
                }

            /////////////////////////////////////////////////////////////////////////////////////////////////////////

            try
            {
                if (direction == 4)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x, y - 1] == 0 && playBoard[x, y - 2] == 0 && playBoard[x, y - 3] == 0 && playBoard[x, y - 4] == 0)
                    {

                        playBoard[x, y] = 6;
                        playBoard[x, y - 1] = 6;
                        playBoard[x, y - 2] = 6;
                        playBoard[x, y - 3] = 6;
                        playBoard[x, y - 4] = 6;
                        return 0;
                    }
                }
            }
            catch
            {
                
                return 1;
            }

            return 1;
        }

        public int setFour(int x, int y, int direction)               //sets Battleship's(3) position
        {
            try
            {
                if (direction == 1)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x - 1, y] == 0 && playBoard[x - 2, y] == 0 && playBoard[x - 3, y] == 0)
                    {

                        playBoard[x, y] = 3;
                        playBoard[x - 1, y] = 3;
                        playBoard[x - 2, y] = 3;
                        playBoard[x - 3, y] = 3;
                        return 0;
                    }

                }
            }
            catch
            {
                return 1;
            }

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

            try
            {
                if (direction == 2)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x, y + 1] == 0 && playBoard[x, y + 2] == 0 && playBoard[x, y + 3] == 0)
                    {

                        playBoard[x, y] = 3;
                        playBoard[x, y + 1] = 3;
                        playBoard[x, y + 2] = 3;
                        playBoard[x, y + 3] = 3;
                        return 0;
                    }

                }
            }
            catch
            {
                
                return 1;
            }

            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            try
            {
                if (direction == 3)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x + 1, y] == 0 && playBoard[x + 2, y] == 0 && playBoard[x + 3, y] == 0)
                    {

                        playBoard[x, y] = 3;
                        playBoard[x + 1, y] = 3;
                        playBoard[x + 2, y] = 3;
                        playBoard[x + 3, y] = 3;
                        return 0;
                    }

                }
            }
            catch
            {
           
                return 1;
            }

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            try
            {
                if (direction == 4)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x, y - 1] == 0 && playBoard[x, y - 2] == 0 && playBoard[x, y - 3] == 0)
                    {

                        playBoard[x, y] = 3;
                        playBoard[x, y - 1] = 3;
                        playBoard[x, y - 2] = 3;
                        playBoard[x, y - 3] = 3;
                        return 0;
                    }

                }
            }
            catch
            {
              
                return 1;
            }
            return 1;
        }

        public int setThree(int x, int y, int direction)              //sets Crusier's(4) position
        {
            try
            {
                if (direction == 1)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x - 1, y] == 0 && playBoard[x - 2, y] == 0)
                    {

                        playBoard[x, y] = 4;
                        playBoard[x - 1, y] = 4;
                        playBoard[x - 2, y] = 4;
                        return 0;
                    }

                }
            }
            catch
            {
                
                return 1;
            }

            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            try
            {
                if (direction == 2)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x, y + 1] == 0 && playBoard[x, y + 2] == 0)
                    {

                        playBoard[x, y] = 4;
                        playBoard[x, y + 1] = 4;
                        playBoard[x, y + 2] = 4;
                        return 0;
                    }

                }
            }
            catch
            {
               
                return 1;
            }

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

            try
            {
                if (direction == 3)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x + 1, y] == 0 && playBoard[x + 2, y] == 0)
                    {

                        playBoard[x, y] = 4;
                        playBoard[x + 1, y] = 4;
                        playBoard[x + 2, y] = 4;
                        return 0;
                    }

                }
            }
            catch
            {
                
                return 1;
            }

            try
            {
                if (direction == 4)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x, y - 1] == 0 && playBoard[x, y - 2] == 0)
                    {

                        playBoard[x, y] = 4;
                        playBoard[x, y - 1] = 4;
                        playBoard[x, y - 2] = 4;
                        return 0;
                    }

                }
            }
            catch
            {
               
                return 1;
            }
            return 1;
        }

        public int setSub(int x, int y, int direction)                //sets Crusier's(4) position
        {
            try
            {
                if (direction == 1)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x - 1, y] == 0 && playBoard[x - 2, y] == 0)
                    {

                        playBoard[x, y] = 4;
                        playBoard[x - 1, y] = 4;
                        playBoard[x - 2, y] = 4;
                        return 0;
                    }

                }
            }
            catch
            {
                
                return 1;
            }

            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            try
            {
                if (direction == 2)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x, y + 1] == 0 && playBoard[x, y + 2] == 0)
                    {

                        playBoard[x, y] = 4;
                        playBoard[x, y + 1] = 4;
                        playBoard[x, y + 2] = 4;
                        return 0;
                    }

                }
            }
            catch
            {
                
                return 1;
            }

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

            try
            {
                if (direction == 3)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x + 1, y] == 0 && playBoard[x + 2, y] == 0)
                    {

                        playBoard[x, y] = 4;
                        playBoard[x + 1, y] = 4;
                        playBoard[x + 2, y] = 4;
                        return 0;
                    }

                }
            }
            catch
            {
               
                return 1;
            }
            ////////////////////////////////////////////////

            try
            {
                if (direction == 4)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x, y - 1] == 0 && playBoard[x, y - 2] == 0)
                    {

                        playBoard[x, y] = 4;
                        playBoard[x, y - 1] = 4;
                        playBoard[x, y - 2] = 4;
                        return 0;
                    }

                }
            }
            catch
            {
                
                return 1;
            }
            return 1;
        }

        public int setRunner(int x, int y, int direction)             //sets Destory's(5) position
        {
            try
            {
                if (direction == 1)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x - 1, y] == 0)
                    {

                        playBoard[x, y] = 5;
                        playBoard[x - 1, y] = 5;
                        return 0;
                    }

                }
            }
            catch
            {
              
                return 1;
            }
            /////////////////////////////////////////////////////

            try
            {
                if (direction == 2)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x, y + 1] == 0)
                    {

                        playBoard[x, y] = 5;
                        playBoard[x, y + 1] = 5;
                        return 0;
                    }

                }
            }
            catch
            {
            
                return 1;
            }

            //////////////////////////////////////////////////////////////////

            try
            {
                if (direction == 3)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x + 1, y] == 0)
                    {

                        playBoard[x, y] = 5;
                        playBoard[x + 1, y] = 5;
                        return 0;
                    }

                }
            }
            catch
            {
             
                return 1;
            }

            /////////////////////////////////////////////////

            try
            {
                if (direction == 4)                                        //1 left, 2 up, 3 right, 4 down
                {
                    if (playBoard[x, y] == 0 && playBoard[x, y - 1] == 0)
                    {
                        playBoard[x, y] = 5;
                        playBoard[x, y - 1] = 5;
                        return 0;
                    }

                }
            }
            catch
            {
              
                return 1;
            }

            return 1;
        }

        public int hitCord(int x, int y)               //use a 1 signify a hit square,  for a hit ship 2 for a miss
        {
            if(playBoard[x,y] == 0)             //two returned == a miss
            {
                playBoard[x, y] = 2;
                return 2;
            }

            if (playBoard[x,y] == 2)            // one returned == already hit
            {
                return 1;
            }

            if (playBoard[x, y] > 2)            //anything else is a hit
            {
                int holder = playBoard[x, y];
                holder = playBoard[x, y];
                playBoard[x, y] = 2;
                return holder;
            }

            return 0;
            
        }

        public int checkCord(int x, int y)             //returns the value of a cord. (t or f)
        {
            return playBoard[x, y];
        }

        public void reset()                             //resets the array to 0's
        {
            for (int x = 0; x < 10; x++)
            {
                for (int y = 0; y < 10; y++)
                {
                    playBoard[x, y] = 0;
                }
            }
        }

        public int winCheck()                           //10 for a not yet, 9 = win
        {
            for (int x = 0; x < 10; x++)
            {
                for (int y = 0; y < 10; y++)
                {
                    if (playBoard[x, y] > 2)           //lose
                    {
                        return 10;
                        
                    }
                }
            }

            return 9;           //win
        }
    }
}
