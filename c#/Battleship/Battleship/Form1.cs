using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

/*
*Name: Cameron Cromer
*Date: 4/21/2016
*Project: Battleship 
*purpose: To hold and operate the parameters of the game boards
*/

namespace Battleship
{
    public partial class Form : System.Windows.Forms.Form
    {
        Board player = new Board();         //player's ship
        Board enemy = new Board();          //enemy's ships


        bool didithitleft = false;
        bool didithitright = false;
        bool didithitup = false;
        bool didithitdown = false;


        int hitholder = 0;


        int enemyholderx = 10;
        int enemyholdery = 10;
        int enemytestx = 10;
        int enemytesty = 10;
        int enemyship = 0;


        Random rnd = new Random();
        int x;
        int y;
        int direction;

        private void win()          //playerwins
        {
            picWin.Visible = true;

            pic0000.Visible = false;             //why pictureboxes. why
            pic0001.Visible = false;
            pic0002.Visible = false;
            pic0003.Visible = false;
            pic0004.Visible = false;
            pic0005.Visible = false;
            pic0006.Visible = false;
            pic0007.Visible = false;
            pic0008.Visible = false;
            pic0009.Visible = false;
            pic0100.Visible = false;
            pic0101.Visible = false;
            pic0102.Visible = false;
            pic0103.Visible = false;
            pic0104.Visible = false;
            pic0105.Visible = false;
            pic0106.Visible = false;
            pic0107.Visible = false;
            pic0108.Visible = false;
            pic0109.Visible = false;
            pic0200.Visible = false;
            pic0201.Visible = false;
            pic0202.Visible = false;
            pic0203.Visible = false;
            pic0204.Visible = false;
            pic0205.Visible = false;
            pic0206.Visible = false;
            pic0207.Visible = false;
            pic0208.Visible = false;
            pic0209.Visible = false;
            pic0300.Visible = false;
            pic0301.Visible = false;
            pic0302.Visible = false;
            pic0303.Visible = false;
            pic0304.Visible = false;
            pic0305.Visible = false;
            pic0306.Visible = false;
            pic0307.Visible = false;
            pic0308.Visible = false;
            pic0309.Visible = false;
            pic0400.Visible = false;
            pic0401.Visible = false;
            pic0402.Visible = false;
            pic0403.Visible = false;
            pic0404.Visible = false;
            pic0405.Visible = false;
            pic0406.Visible = false;
            pic0407.Visible = false;
            pic0408.Visible = false;
            pic0409.Visible = false;
            pic0500.Visible = false;
            pic0501.Visible = false;
            pic0502.Visible = false;
            pic0503.Visible = false;
            pic0504.Visible = false;
            pic0505.Visible = false;
            pic0506.Visible = false;
            pic0507.Visible = false;
            pic0508.Visible = false;
            pic0509.Visible = false;
            pic0600.Visible = false;
            pic0601.Visible = false;
            pic0602.Visible = false;
            pic0603.Visible = false;
            pic0604.Visible = false;
            pic0605.Visible = false;
            pic0606.Visible = false;
            pic0607.Visible = false;
            pic0608.Visible = false;
            pic0609.Visible = false;
            pic0700.Visible = false;
            pic0701.Visible = false;
            pic0702.Visible = false;
            pic0703.Visible = false;
            pic0704.Visible = false;
            pic0705.Visible = false;
            pic0706.Visible = false;
            pic0707.Visible = false;
            pic0708.Visible = false;
            pic0709.Visible = false;
            pic0800.Visible = false;
            pic0801.Visible = false;
            pic0802.Visible = false;
            pic0803.Visible = false;
            pic0804.Visible = false;
            pic0805.Visible = false;
            pic0806.Visible = false;
            pic0807.Visible = false;
            pic0808.Visible = false;
            pic0809.Visible = false;
            pic0900.Visible = false;
            pic0901.Visible = false;
            pic0902.Visible = false;
            pic0903.Visible = false;
            pic0904.Visible = false;
            pic0905.Visible = false;
            pic0906.Visible = false;
            pic0907.Visible = false;
            pic0908.Visible = false;
            pic0909.Visible = false;
        }

        private void lose()             //player lose
        {
            picLose.Visible = true;


            pic0000.Visible = false;             //why pictureboxes. why
            pic0001.Visible = false;
            pic0002.Visible = false;
            pic0003.Visible = false;
            pic0004.Visible = false;
            pic0005.Visible = false;
            pic0006.Visible = false;
            pic0007.Visible = false;
            pic0008.Visible = false;
            pic0009.Visible = false;
            pic0100.Visible = false;
            pic0101.Visible = false;
            pic0102.Visible = false;
            pic0103.Visible = false;
            pic0104.Visible = false;
            pic0105.Visible = false;
            pic0106.Visible = false;
            pic0107.Visible = false;
            pic0108.Visible = false;
            pic0109.Visible = false;
            pic0200.Visible = false;
            pic0201.Visible = false;
            pic0202.Visible = false;
            pic0203.Visible = false;
            pic0204.Visible = false;
            pic0205.Visible = false;
            pic0206.Visible = false;
            pic0207.Visible = false;
            pic0208.Visible = false;
            pic0209.Visible = false;
            pic0300.Visible = false;
            pic0301.Visible = false;
            pic0302.Visible = false;
            pic0303.Visible = false;
            pic0304.Visible = false;
            pic0305.Visible = false;
            pic0306.Visible = false;
            pic0307.Visible = false;
            pic0308.Visible = false;
            pic0309.Visible = false;
            pic0400.Visible = false;
            pic0401.Visible = false;
            pic0402.Visible = false;
            pic0403.Visible = false;
            pic0404.Visible = false;
            pic0405.Visible = false;
            pic0406.Visible = false;
            pic0407.Visible = false;
            pic0408.Visible = false;
            pic0409.Visible = false;
            pic0500.Visible = false;
            pic0501.Visible = false;
            pic0502.Visible = false;
            pic0503.Visible = false;
            pic0504.Visible = false;
            pic0505.Visible = false;
            pic0506.Visible = false;
            pic0507.Visible = false;
            pic0508.Visible = false;
            pic0509.Visible = false;
            pic0600.Visible = false;
            pic0601.Visible = false;
            pic0602.Visible = false;
            pic0603.Visible = false;
            pic0604.Visible = false;
            pic0605.Visible = false;
            pic0606.Visible = false;
            pic0607.Visible = false;
            pic0608.Visible = false;
            pic0609.Visible = false;
            pic0700.Visible = false;
            pic0701.Visible = false;
            pic0702.Visible = false;
            pic0703.Visible = false;
            pic0704.Visible = false;
            pic0705.Visible = false;
            pic0706.Visible = false;
            pic0707.Visible = false;
            pic0708.Visible = false;
            pic0709.Visible = false;
            pic0800.Visible = false;
            pic0801.Visible = false;
            pic0802.Visible = false;
            pic0803.Visible = false;
            pic0804.Visible = false;
            pic0805.Visible = false;
            pic0806.Visible = false;
            pic0807.Visible = false;
            pic0808.Visible = false;
            pic0809.Visible = false;
            pic0900.Visible = false;
            pic0901.Visible = false;
            pic0902.Visible = false;
            pic0903.Visible = false;
            pic0904.Visible = false;
            pic0905.Visible = false;
            pic0906.Visible = false;
            pic0907.Visible = false;
            pic0908.Visible = false;
            pic0909.Visible = false;
        }   

        private void computerTurn()         //pc's turn
        {
            try
            {
                int playerwin;
                playerwin = enemy.winCheck();           //checks to see if player won before the pc turn starts
                                                        //beats putting that on every pic box

                if (playerwin == 9)
                {
                    win();
                    end();
                  
                    return;
                }

                if (enemyholderx == 10)         //normal pc turn
                {
                    int holder;
                    x = rnd.Next(10);
                    y = rnd.Next(10);
                    holder = player.hitCord(x, y);

                    while (holder == 1)         //already hit square, so its a re roll
                    {
                        x = rnd.Next(10);
                        y = rnd.Next(10);
                        holder = player.hitCord(x, y);
                    }

                    if (holder == 2)                           
                    {
                        lblpc.Text = "the pc missed";
                        return;
                    }

                    if (holder == 3)        //Battleship, 4 hits	
                    {
                        lblpc.Text = "Your Battleship was hit!";
                        enemyholderx = x;
                        enemyholdery = y;
                        didithitleft = true;
                        enemyship = 3;              //take one away for the freshly hit square

                        int win;
                        win = player.winCheck();

                        if (win == 9)
                        {
                            lose();
                            end();
                            
                        }
                        return;

                    }

                    if (holder == 4) //////////////Crusier (3hits)
                    {
                        lblpc.Text = "Your Crusier was hit!";
                        enemyholderx = x;
                        enemyholdery = y;
                        didithitleft = true;
                        enemyship = 2;

                        int win;
                        win = player.winCheck();
                        if (win == 9)
                        {
                            lose();
                            end();
                            
                        }
                        return;
                    }

                    if (holder == 5)        //runner, 2 hits
                    {
                        lblpc.Text = "Your Runner was hit!";
                        enemyholderx = x;
                        enemyholdery = y;
                        didithitleft = true;
                        enemyship = 1;
                        int win;
                        win = player.winCheck();

                        if (win == 9)
                        {
                            lose();
                            end();
                          
                        }
                        return;
                    }

                    if (holder == 6)            //carrier, 5 hits
                    {
                        lblpc.Text = "Your Carrier was hit!";
                        enemyholderx = x;
                        enemyholdery = y;
                        didithitleft = true;
                        enemyship = 4;

                        int win;
                        win = player.winCheck();

                        if (win == 9)
                        {
                            lose();
                            end();
                            
                        }
                        return;
                    }
                }


                ///////////////////////////////////////////////////////////////////////////////////////

                if (enemyholderx < 10 && didithitleft == true)
                {
                    int holder;

                        if (enemytestx > enemyholderx)              //first time in loop
                        {
                            enemytestx = enemyholderx;
                        }

                        if (enemytestx > 0)             //returns a already hit square to move to next part of fnc
                        {
                            enemytestx--;
                        }

                        holder = player.hitCord(enemytestx, enemyholdery);  //fires at the board

                        if (holder == 1)                //already hit this square
                        {
                            didithitleft = false;
                            didithitright = true;
                            enemytestx = 10;
                        }

                        if (holder == 2)                //returns the center back to the orginal hit position, if it missed
                        {
                            lblpc.Text = "the pc missed";
                            didithitleft = false;
                            didithitright = true;
                            enemytestx = 10;                //this returns for the if to be reassigned
                            int win;
                            win = player.winCheck();

                            if (win == 9)
                        {
                            lose();
                            end();
                            
                            }
                            return;
                        }

                        if (holder > 2)             //yeet got a hit
                        {
                            enemyship = enemyship - 1;
                            if (holder == 3)
                            {
                                lblpc.Text = "Your Battleship was hit!";
                            }

                            if (holder == 4)
                            {
                                lblpc.Text = "Your Crusier was hit!";
                            }

                            if (holder == 5)
                            {
                                lblpc.Text = "Your Runner was hit!";
                            }

                            if (holder == 6)
                            {
                                lblpc.Text = "Your Carrier was hit!";
                            }
                        }

                        if (enemyship == 0)             //the ship has sunk
                        {
                            enemyholderx = 10;
                            enemyholdery = 10;
                            didithitleft = false;
                            didithitright = false;
                            didithitup = false;
                            didithitdown = false;
                            int win;
                            win = player.winCheck();

                            if (win == 9)
                        {
                            lose();
                            end();
                            
                            }
                            return;
                        }
                    
                }

                //////////////////////////////////////////////////////////////////////////////////////////////

                if (enemyholderx < 10 && didithitright == true)
                {
                    int holder;

                        if (enemytestx > enemyholderx)              //first time in loop
                        {
                            enemytestx = enemyholderx;
                        }

                        if (enemytestx < 9)             //returns a already hit square to move to next part of fnc
                        {
                            enemytestx++;
                        }
                        holder = player.hitCord(enemytestx, enemyholdery);

                        if (holder == 1)                //same notes as above
                        {
                            didithitright = false;
                            didithitup = true;
                            enemytestx = 10;
                        }

                        if (holder == 2)
                        {
                            lblpc.Text = "the pc missed";
                            didithitright = false;
                            didithitup = true;
                            enemytestx = 10;       //this returns the to the original position
                            int win;
                            win = player.winCheck();

                            if (win == 9)
                        {
                            lose();
                            end();
                      
                            }
                            return;
                        }

                        if (holder > 2)
                        {
                            enemyship = enemyship - 1;
                            if (holder == 3)
                            {
                                lblpc.Text = "Your Battleship was hit!";
                            }

                            if (holder == 4)
                            {
                                lblpc.Text = "Your Crusier was hit!";
                            }

                            if (holder == 5)
                            {
                                lblpc.Text = "Your Runner was hit!";
                            }

                            if (holder == 6)
                            {
                                lblpc.Text = "Your Carrier was hit!";
                            }
                        }

                        if (enemyship == 0)
                        {
                            enemyholderx = 10;
                            enemyholdery = 10;
                            didithitleft = false;
                            didithitright = false;
                            didithitup = false;
                            didithitdown = false;
                            int win;
                            win = player.winCheck();

                            if (win == 9)
                        {
                            lose();
                            end();
                            
                            }
                            return;
                        }
                       
                    }
               

                ////////////////////////////////////////////////////////////////////////////////////

                if (enemyholderx < 10 && didithitup == true)
                {
                    int holder;

                        if (enemytesty > enemyholdery)              //first time in loop
                        {
                            enemytesty = enemyholdery;
                        }

                        if (enemytesty > 0)             //returns a already hit square to move to next part of fnc
                        {
                            enemytesty--;
                        }

                        holder = player.hitCord(enemyholderx, enemytesty);

                        if (holder == 1)
                        {
                            didithitup = false;
                            didithitdown = true;
                            enemytesty = 10;
                        }

                        if (holder == 2)
                        {
                            lblpc.Text = "the pc missed";
                            didithitup = false;
                            didithitdown = true;
                            enemytesty = 10;       //this returns the to the original position
                            int win;
                            win = player.winCheck();

                            if (win == 9)
                        {
                            lose();
                            end();
                            
                        }
                            return;
                        }
                        if (holder > 2)
                        {
                            enemyship = enemyship - 1;
                            if (holder == 3)
                            {
                                lblpc.Text = "Your Battleship was hit!";
                            }

                            if (holder == 4)
                            {
                                lblpc.Text = "Your Crusier was hit!";
                            }

                            if (holder == 5)
                            {
                                lblpc.Text = "Your Runner was hit!";
                            }

                            if (holder == 6)
                            {
                                lblpc.Text = "Your Carrier was hit!";
                            }
                        }

                        if (enemyship == 0)
                        {
                            enemyholderx = 10;
                            enemyholdery = 10;
                            didithitleft = false;
                            didithitright = false;
                            didithitup = false;
                            didithitdown = false;
                            int win;
                            win = player.winCheck();

                            if (win == 9)
                        {
                            lose();
                            end();
                            
                            }
                            return;
                        }
                }

                ////////////////////////////////////////////////////////////////////////////////////

                if (enemyholderx < 10 && didithitdown == true)
                {
                    int holder;

                    if (enemytesty > enemyholdery)              //first time in loop
                    {
                        enemytesty = enemyholdery;
                    }

                    if (enemytesty < 9)             //returns a already hit square to move to next part of fnc
                    {
                        enemytesty++;
                    }
                    holder = player.hitCord(enemyholderx, enemytesty);

                    if (holder == 1)
                    {
                        didithitdown = false;
                        didithitleft = true;
                        enemytesty = 10;
                    }


                    if (holder == 2)
                    {
                        lblpc.Text = "the pc missed";
                        didithitdown = false;
                        didithitleft = true;
                        enemytesty = 10;       //this returns the to the original position
                        int win;
                        win = player.winCheck();

                        if (win == 9)
                        {
                            lose();
                            end();
                            
                        }
                        return;
                    }

                    if (holder > 2)
                    {
                        enemyship = enemyship - 1;
                        if (holder == 3)
                        {
                            lblpc.Text = "Your Battleship was hit!";
                        }

                        if (holder == 4)
                        {
                            lblpc.Text = "Your Crusier was hit!";
                        }

                        if (holder == 5)
                        {
                            lblpc.Text = "Your Runner was hit!";
                        }

                        if (holder == 6)
                        {
                            lblpc.Text = "Your Carrier was hit!";
                        }
                    }

                    if (enemyship == 0)
                    {
                        enemyholderx = 10;
                        enemyholdery = 10;
                        didithitleft = false;
                        didithitright = false;
                        didithitup = false;
                        didithitdown = false;
                        int win;
                        win = player.winCheck();

                        if (win == 9)
                        {
                            lose();
                            end();
                            
                        }
                        return;
                    }

                    if (holder == 1)
                    {
                        enemyholderx = 10;
                        enemyholdery = 10;
                        didithitleft = false;
                        didithitright = false;
                        didithitup = false;
                        didithitdown = false;
                        int win;
                        win = player.winCheck();

                        if (win == 9)
                        {
                            lose();
                            end();
                        }
                        return;
                    }
                }
                   
                
            }         
            catch
            {
                lblDirections.Text = "it broke";
            }
        }
        

        private void loadIn()                   //loads in the board photo and cpu ship placement
        {
            picBoard.Visible = true;
            picBlackBack.Visible = true;
            picStart.Visible = false;

            lblDirections.Text = "Please input the Cordinates and Oriention of the Carrier (Five Hit boxes).";

            picblack.Visible = false;

            for (int i = 0; i < 5; i++)                     //places enemy ships
            {
                butship1.Visible = true;
                butship2.Visible = true;
                butship3.Visible = true;
                butship4.Visible = true;
                butship5.Visible = true;

                int check = 0;
                x = rnd.Next(10);
                y = rnd.Next(10);
                direction = rnd.Next(1, 5);

                if (i ==  0)
                {
                    check = enemy.setFive(x, y, direction);

                    while (check == 1)                 //incase the placement failed
                    {
                        x = rnd.Next(10);
                        y = rnd.Next(10);
                        direction = rnd.Next(1, 5);
                        check = enemy.setFive(x, y, direction);
                    }
                }

                if (i == 1)
                {
                    check = enemy.setFour(x, y, direction);

                    while (check == 1)
                    {
                        x = rnd.Next(10);
                        y = rnd.Next(10);
                        direction = rnd.Next(1, 5);
                        check = enemy.setFour(x, y, direction);
                    }
                }

                if (i == 2)
                {
                    check = enemy.setThree(x, y, direction);

                    while (check == 1)
                    {
                        x = rnd.Next(10);
                        y = rnd.Next(10);
                        direction = rnd.Next(1, 5);
                        check = enemy.setThree(x, y, direction);
                    }
                }

                if(i == 3)
                {
                   check = enemy.setSub(x, y, direction);

                    while (check == 1)
                    {
                        x = rnd.Next(10);
                        y = rnd.Next(10);
                        direction = rnd.Next(1, 5);
                        check = enemy.setSub(x, y, direction);
                    }
                }

                if (i == 4)
                {
                   check = enemy.setRunner(x, y, direction);

                    while (check == 1)
                    {
                        x = rnd.Next(10);
                        y = rnd.Next(10);
                        direction = rnd.Next(1, 5);
                        check = enemy.setRunner(x, y, direction);
                    }
                }
            }

        }

        public Form()
        {
            InitializeComponent();
        }

        private void picStart_Click(object sender, EventArgs e)
        {
            loadIn();                           //starts game
        }

        private void pic0000_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(0, 0);

           if (hitholder <= 2)
            {
               pic0000.BackColor = Color.Blue;
               
            }
            else
            {
                lblDirections.Text = "You hit a ship!";
               pic0000.BackColor = Color.Red;
            }

            pic0000.Enabled = false;
            computerTurn();
          
        }

        private void pic0100_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(1, 0);

            if (hitholder <= 2)
            {
                pic0100.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0100.BackColor = Color.Red;
            }
            pic0100.Enabled = false;
            computerTurn();
        }

        private void pic0200_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(2, 0);

            if (hitholder <= 2)
            {
                pic0200.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0200.BackColor = Color.Red;
            }
            pic0200.Enabled = false;
            computerTurn();
        }

        private void pic0300_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(3, 0);

            if (hitholder <= 2)
            {
                pic0300.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0300.BackColor = Color.Red;
            }
            pic0300.Enabled = false;
            computerTurn();
        }

        private void pic0400_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(4, 0);

            if (hitholder <= 2)
            {
                pic0400.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0400.BackColor = Color.Red;
            }
            pic0400.Enabled = false;
            computerTurn();
        }

        private void pic0500_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(5, 0);

            if (hitholder <= 2)
            {
                pic0500.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0500.BackColor = Color.Red;
            }
            pic0500.Enabled = false;
            computerTurn();
        }

        private void pic0600_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(6, 0);

            if (hitholder <= 2)
            {
                pic0600.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0600.BackColor = Color.Red;
            }
            pic0600.Enabled = false;
            computerTurn();
        }

        private void pic0700_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(7, 0);

            if (hitholder <= 2)
            {
                pic0700.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0700.BackColor = Color.Red;
            }
            pic0700.Enabled = false;
            computerTurn();
        }

        private void pic0800_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(8, 0);

            if (hitholder <= 2)
            {
                pic0800.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0800.BackColor = Color.Red;
            }
            pic0800.Enabled = false;
            computerTurn();
        }

        private void pic0900_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(9, 0);

            if (hitholder <= 2)
            {
                pic0900.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0900.BackColor = Color.Red;
            }
            pic0900.Enabled = false;
            computerTurn();
        }

        private void pic0001_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(0, 1);

            if (hitholder <= 2)
            {
                pic0001.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0001.BackColor = Color.Red;
            }
            pic0001.Enabled = false;
            computerTurn();
        }

        private void pic0101_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(1, 1);

            if (hitholder <= 2)
            {
                pic0101.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0101.BackColor = Color.Red;
            }
            pic0101.Enabled = false;
            computerTurn();
        }

        private void pic0201_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(2, 1);

            if (hitholder <= 2)
            {
                pic0201.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0201.BackColor = Color.Red;
            }
            pic0201.Enabled = false;
            computerTurn();
        }

        private void pic0301_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(3, 1);

            if (hitholder <= 2)
            {
                pic0301.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0301.BackColor = Color.Red;
            }
            pic0301.Enabled = false;
            computerTurn();
        }
       
        private void pic0401_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(4, 1);

            if (hitholder <= 2)
            {
                pic0401.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0401.BackColor = Color.Red;
            }
            pic0401.Enabled = false;
            computerTurn();
        }

        private void pic0501_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(5, 1);

            if (hitholder <= 2)
            {
                pic0501.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0501.BackColor = Color.Red;
            }
            pic0501.Enabled = false;
            computerTurn();
        }

        private void pic0601_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(6, 1);

            if (hitholder <= 2)
            {
                pic0601.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0601.BackColor = Color.Red;
            }
            pic0601.Enabled = false;
            computerTurn();
        }

        private void pic0701_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(7, 1);

            if (hitholder <= 2)
            {
                pic0701.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0701.BackColor = Color.Red;
            }
            pic0701.Enabled = false;
            computerTurn();
        }

        private void pic0801_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(8, 1);

            if (hitholder <= 2)
            {
                pic0801.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0801.BackColor = Color.Red;
            }
            pic0801.Enabled = false;
            computerTurn();
        }

        private void pic0901_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(9, 1);

            if (hitholder <= 2)
            {
                pic0901.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0901.BackColor = Color.Red;
            }
            pic0901.Enabled = false;
            computerTurn();
        }

        private void pic0002_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(0, 2);

            if (hitholder <= 2)
            {
                pic0002.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0002.BackColor = Color.Red;
            }
            pic0002.Enabled = false;
            computerTurn();
        }

        private void pic0102_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(1, 2);

            if (hitholder <= 2)
            {
                pic0102.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0102.BackColor = Color.Red;
            }
            pic0102.Enabled = false;
            computerTurn();
        }

        private void pic0202_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(2, 2);

            if (hitholder <= 2)
            {
                pic0202.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0202.BackColor = Color.Red;
            }
            pic0202.Enabled = false;
            computerTurn();
        }

        private void pic0302_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(3, 2);

            if (hitholder <= 2)
            {
                pic0302.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0302.BackColor = Color.Red;
            }
            pic0302.Enabled = false;
            computerTurn();
        }

        private void pic0402_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(4, 2);

            if (hitholder <= 2)
            {
                pic0402.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0402.BackColor = Color.Red;
            }
            pic0402.Enabled = false;
            computerTurn();
        }

        private void pic0502_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(5, 2);

            if (hitholder <= 2)
            {
                pic0502.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0502.BackColor = Color.Red;
            }
            pic0502.Enabled = false;
            computerTurn();
        }

        private void pic0602_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(6, 2);

            if (hitholder <= 2)
            {
                pic0602.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0602.BackColor = Color.Red;
            }
            pic0602.Enabled = false;
            computerTurn();
        }

        private void pic0702_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(7, 2);

            if (hitholder <= 2)
            {
                pic0702.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0702.BackColor = Color.Red;
            }
            pic0702.Enabled = false;
            computerTurn();
        }

        private void pic0802_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(8, 2);

            if (hitholder <= 2)
            {
                pic0802.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0802.BackColor = Color.Red;
            }
            pic0802.Enabled = false;
            computerTurn();
        }

        private void pic0902_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(9, 2);

            if (hitholder <= 2)
            {
                pic0902.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0902.BackColor = Color.Red;
            }
            pic0902.Enabled = false;
            computerTurn();
        }

        private void pic0003_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(0, 3);

            if (hitholder <= 2)
            {
                pic0003.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0003.BackColor = Color.Red;
            }
            pic0003.Enabled = false;
            computerTurn();
        }

        private void pic0103_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(1, 3);

            if (hitholder <= 2)
            {
                pic0103.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0103.BackColor = Color.Red;
            }
            pic0103.Enabled = false;
            computerTurn();
        }

        private void pic0203_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(2, 3);

            if (hitholder <= 2)
            {
                pic0203.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0203.BackColor = Color.Red;
            }
            pic0203.Enabled = false;
            computerTurn();
        }

        private void pic0303_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(3, 3);

            if (hitholder <= 2)
            {
                pic0303.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0303.BackColor = Color.Red;
            }
            pic0303.Enabled = false;
            computerTurn();
        }

        private void pic0403_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(4, 3);

            if (hitholder <= 2)
            {
                pic0403.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0403.BackColor = Color.Red;
            }
            pic0403.Enabled = false;
            computerTurn();
        }

        private void pic0503_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(5, 3);

            if (hitholder <= 2)
            {
                pic0503.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0503.BackColor = Color.Red;
            }
            pic0503.Enabled = false;
            computerTurn();
        }

        private void pic0603_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(6, 3);

            if (hitholder <= 2)
            {
                pic0603.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0603.BackColor = Color.Red;
            }
            pic0603.Enabled = false;
            computerTurn();
        }

        private void pic0703_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(7, 3);

            if (hitholder <= 2)
            {
                pic0703.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0703.BackColor = Color.Red;
            }
            pic0703.Enabled = false;
            computerTurn();
        }

        private void pic0803_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(8, 3);

            if (hitholder <= 2)
            {
                pic0803.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0803.BackColor = Color.Red;
            }
            pic0803.Enabled = false;
            computerTurn();
        }

        private void pic0903_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(9, 4);

            if (hitholder <= 2)
            {
                pic0903.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0903.BackColor = Color.Red;
            }
            pic0903.Enabled = false;
            computerTurn();
        }

        private void pic0004_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(0, 4);

            if (hitholder <= 2)
            {
                pic0004.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0004.BackColor = Color.Red;
            }
            pic0004.Enabled = false;
            computerTurn();
        }

        private void pic0104_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(1, 4);

            if (hitholder <= 2)
            {
                pic0104.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0104.BackColor = Color.Red;
            }
            pic0104.Enabled = false;
            computerTurn();
        }

        private void pic0204_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(2, 4);

            if (hitholder <= 2)
            {
                pic0204.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0204.BackColor = Color.Red;
            }
            pic0204.Enabled = false;
            computerTurn();
        }

        private void pic0304_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(3, 4);

            if (hitholder <= 2)
            {
                pic0304.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0304.BackColor = Color.Red;
            }
            pic0304.Enabled = false;
            computerTurn();
        }

        private void pic0404_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(4, 4);

            if (hitholder <= 2)
            {
                pic0404.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0404.BackColor = Color.Red;
            }
            pic0404.Enabled = false;
            computerTurn();
        }

        private void pic0504_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(5, 4);

            if (hitholder <= 2)
            {
                pic0504.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0504.BackColor = Color.Red;
            }
            pic0504.Enabled = false;
            computerTurn();
        }

        private void pic0604_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(6, 4);

            if (hitholder <= 2)
            {
                pic0604.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0604.BackColor = Color.Red;
            }
            pic0604.Enabled = false;
            computerTurn();
        }

        private void pic0704_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(7, 4);

            if (hitholder <= 2)
            {
                pic0704.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0704.BackColor = Color.Red;
            }
            pic0704.Enabled = false;
            computerTurn();
        }

        private void pic0804_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(8, 4);

            if (hitholder <= 2)
            {
                pic0804.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0804.BackColor = Color.Red;
            }
            pic0804.Enabled = false;
            computerTurn();
        }

        private void pic0904_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(9, 4);

            if (hitholder <= 2)
            {
                pic0904.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0904.BackColor = Color.Red;
            }
            pic0904.Enabled = false;
            computerTurn();
        }

        private void pic0005_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(0, 5);

            if (hitholder <= 2)
            {
                pic0005.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0005.BackColor = Color.Red;
            }
            pic0005.Enabled = false;
            computerTurn();
        }

        private void pic0105_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(1, 5);

            if (hitholder <= 2)
            {
                pic0105.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0105.BackColor = Color.Red;
            }
            pic0105.Enabled = false;
            computerTurn();
        }

        private void pic0205_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(2, 5);

            if (hitholder <= 2)
            {
                pic0205.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0205.BackColor = Color.Red;
            }
            pic0205.Enabled = false;
            computerTurn();
        }

        private void pic0305_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(3, 5);

            if (hitholder <= 2)
            {
                pic0305.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0305.BackColor = Color.Red;
            }
            pic0305.Enabled = false;
            computerTurn();
        }

        private void pic0405_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(4, 5);

            if (hitholder <= 2)
            {
                pic0405.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0405.BackColor = Color.Red;
            }
            pic0405.Enabled = false;
            computerTurn();
        }

        private void pic0505_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(5, 5);

            if (hitholder <= 2)
            {
                pic0505.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0505.BackColor = Color.Red;
            }
            pic0505.Enabled = false;
            computerTurn();
        }

        private void pic0605_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(6, 5);

            if (hitholder <= 2)
            {
                pic0605.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0605.BackColor = Color.Red;
            }
            pic0605.Enabled = false;
            computerTurn();
        }

        private void pic0705_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(7, 5);

            if (hitholder <= 2)
            {
                pic0705.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0705.BackColor = Color.Red;
            }
            pic0705.Enabled = false;
            computerTurn();
        }

        private void pic0805_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(8, 5);

            if (hitholder <= 2)
            {
                pic0805.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0805.BackColor = Color.Red;
            }
            pic0805.Enabled = false;
            computerTurn();

        }

        private void pic0905_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(9, 5);

            if (hitholder <= 2)
            {
                pic0905.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0905.BackColor = Color.Red;
            }
            pic0905.Enabled = false;
            computerTurn();
        }

        private void pic0006_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(0, 6);

            if (hitholder <= 2)
            {
                pic0006.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0006.BackColor = Color.Red;
            }
            pic0006.Enabled = false;
            computerTurn();
        }

        private void pic0106_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(1, 6);

            if (hitholder <= 2)
            {
                pic0106.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0106.BackColor = Color.Red;
            }
            pic0106.Enabled = false;
            computerTurn();
        }

        private void pic0206_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(2, 6);

            if (hitholder <= 2)
            {
                pic0206.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0206.BackColor = Color.Red;
            }
            pic0206.Enabled = false;
            computerTurn();
        }

        private void pic0306_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(3, 6);

            if (hitholder <= 2)
            {
                pic0306.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0306.BackColor = Color.Red;
            }
            pic0306.Enabled = false;
            computerTurn();
        }

        private void pic0406_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(4, 6);

            if (hitholder <= 2)
            {
                pic0406.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0406.BackColor = Color.Red;
            }
            pic0406.Enabled = false;
            computerTurn();
        }

        private void pic0506_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(5, 6);

            if (hitholder <= 2)
            {
                pic0506.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0506.BackColor = Color.Red;
            }
            pic0506.Enabled = false;
            computerTurn();
        }

        private void pic0606_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(6, 6);

            if (hitholder <= 2)
            {
                pic0606.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0606.BackColor = Color.Red;
            }
            pic0606.Enabled = false;
            computerTurn();
        }

        private void pic0706_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(7, 6);

            if (hitholder <= 2)
            {
                pic0706.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0706.BackColor = Color.Red;
            }
            pic0706.Enabled = false;
            computerTurn();
        }

        private void pic0806_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(8, 6);

            if (hitholder <= 2)
            {
                pic0806.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0806.BackColor = Color.Red;
            }
            pic0806.Enabled = false;
            computerTurn();
        }

        private void pic0906_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(9, 6);

            if (hitholder <= 2)
            {
                pic0906.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0906.BackColor = Color.Red;
            }
            pic0906.Enabled = false;
            computerTurn();
        }

        private void pic0007_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(0, 7);

            if (hitholder <= 2)
            {
                pic0007.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0007.BackColor = Color.Red;
            }
            pic0007.Enabled = false;
            computerTurn();
        }

        private void pic0107_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(1, 7);

            if (hitholder <= 2)
            {
                pic0107.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0107.BackColor = Color.Red;
            }
            pic0107.Enabled = false;
            computerTurn();
        }

        private void pic0207_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(2, 7);

            if (hitholder <= 2)
            {
                pic0207.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0207.BackColor = Color.Red;
            }
            pic0207.Enabled = false;
            computerTurn();
        }

        private void pic0307_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(3, 7);

            if (hitholder <= 2)
            {
                pic0307.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0307.BackColor = Color.Red;
            }
            pic0307.Enabled = false;
            computerTurn();

        }

        private void pic0407_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(4, 7);

            if (hitholder <= 2)
            {
                pic0407.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0407.BackColor = Color.Red;
            }
            pic0407.Enabled = false;
            computerTurn();
        }

        private void pic0507_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(5, 7);

            if (hitholder <= 2)
            {
                pic0507.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0507.BackColor = Color.Red;
            }
            pic0507.Enabled = false;
            computerTurn();
        }

        private void pic0607_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(6, 7);

            if (hitholder <= 2)
            {
                pic0607.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0607.BackColor = Color.Red;
            }
            pic0607.Enabled = false;
            computerTurn();
        }

        private void pic0707_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(7, 7);

            if (hitholder <= 2)
            {
                pic0707.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0707.BackColor = Color.Red;
            }
            pic0707.Enabled = false;
            computerTurn();
        }

        private void pic0807_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(8, 7);

            if (hitholder <= 2)
            {
                pic0807.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0807.BackColor = Color.Red;
            }
            pic0807.Enabled = false;
            computerTurn();
        }

        private void pic0907_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(9, 7);

            if (hitholder <= 2)
            {
                pic0907.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0907.BackColor = Color.Red;
            }
            pic0907.Enabled = false;
            computerTurn();
        }

        private void pic0008_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(0, 8);

            if (hitholder <= 2)
            {
                pic0008.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0008.BackColor = Color.Red;
            }
            pic0008.Enabled = false;
            computerTurn();
        }

        private void pic0108_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(1, 8);

            if (hitholder <= 2)
            {
                pic0108.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0108.BackColor = Color.Red;
            }
            pic0108.Enabled = false;
            computerTurn();
        }

        private void pic0208_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(2, 8);

            if (hitholder <= 2)
            {
                pic0208.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0208.BackColor = Color.Red;
            }
            pic0208.Enabled = false;
            computerTurn();
        }

        private void pic0308_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(3, 8);

            if (hitholder <= 2)
            {
                pic0308.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0308.BackColor = Color.Red;
            }
            pic0308.Enabled = false;
            computerTurn();
        }

        private void pic0408_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(4, 8);

            if (hitholder <= 2)
            {
                pic0408.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0408.BackColor = Color.Red;
            }
            pic0408.Enabled = false;
            computerTurn();
        }

        private void pic0508_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(5, 8);

            if (hitholder <= 2)
            {
                pic0508.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0508.BackColor = Color.Red;
            }
            pic0508.Enabled = false;
            computerTurn();
        }

        private void pic0608_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(6, 8);

            if (hitholder <= 2)
            {
                pic0608.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0608.BackColor = Color.Red;
            }
            pic0608.Enabled = false;
            computerTurn();
        }

        private void pic0708_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(7, 8);

            if (hitholder <= 2)
            {
                pic0708.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0708.BackColor = Color.Red;
            }
            pic0708.Enabled = false;
            computerTurn();
        }

        private void pic0808_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(8, 8);

            if (hitholder <= 2)
            {
                pic0808.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0808.BackColor = Color.Red;
            }
            pic0808.Enabled = false;
            computerTurn();
        }

        private void pic0908_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(9, 8);

            if (hitholder <= 2)
            {
                pic0908.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0908.BackColor = Color.Red;
            }
            pic0908.Enabled = false;
            computerTurn();
        }

        private void pic0009_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(0, 9);

            if (hitholder <= 2)
            {
                pic0009.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0009.BackColor = Color.Red;
            }
            pic0009.Enabled = false;
            computerTurn();
        }

        private void pic0109_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(1, 9);

            if (hitholder <= 2)
            {
                pic0109.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0109.BackColor = Color.Red;
            }
            pic0109.Enabled = false;
            computerTurn();
        }

        private void pic0209_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(2, 9);

            if (hitholder <= 2)
            {
                pic0209.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0209.BackColor = Color.Red;
            }
            pic0209.Enabled = false;
            computerTurn();
        }

        private void pic0309_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(3, 9);

            if (hitholder <= 2)
            {
                pic0309.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0309.BackColor = Color.Red;
            }
            pic0309.Enabled = false;
            computerTurn();
        }

        private void pic0409_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(4, 9);

            if (hitholder <= 2)
            {
                pic0409.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0409.BackColor = Color.Red;
            }
            pic0409.Enabled = false;
            computerTurn();
        }

        private void pic0509_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(5, 9);

            if (hitholder <= 2)
            {
                pic0509.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0509.BackColor = Color.Red;
            }
            pic0509.Enabled = false;
            computerTurn();
        }

        private void pic0609_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(6, 9);

            if (hitholder <= 2)
            {
                pic0609.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0609.BackColor = Color.Red;
            }
            pic0609.Enabled = false;
            computerTurn();
        }

        private void pic0709_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(7, 9);

            if (hitholder <= 2)
            {
                pic0709.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0709.BackColor = Color.Red;
            }
            pic0709.Enabled = false;
            computerTurn();
        }

        private void pic0809_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(8, 9);

            if (hitholder <= 2)
            {
                pic0809.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0809.BackColor = Color.Red;
            }
            pic0809.Enabled = false;
            computerTurn();
        }

        private void pic0909_Click(object sender, EventArgs e)
        {
            hitholder = enemy.hitCord(9, 9);

            if (hitholder <= 2)
            {
                pic0909.BackColor = Color.Blue;

            }
            else
            {
                lblDirections.Text = "You hit a ship!";
                pic0909.BackColor = Color.Red;
            }
            pic0909.Enabled = false;
            computerTurn();
        }

        private void butship1_Click(object sender, EventArgs e)
        {

            try
            {
                int holder = 10;
            int holdery = int.Parse(txtY.Text);
            int holderrotation = 0;
            holdery = holdery - 1;

       
                if (txtX.Text == "A".ToString() || txtX.Text == 'a'.ToString())
                {
                    holder = 0;
                }

                if (txtX.Text == 'B'.ToString() || txtX.Text == 'b'.ToString())
                {
                    holder = 1;
                }

                if (txtX.Text == 'C'.ToString() || txtX.Text == 'c'.ToString())
                {
                    holder = 2;
                }
                if (txtX.Text == 'D'.ToString() || txtX.Text == 'd'.ToString())
                {
                    holder = 3;
                }
                if (txtX.Text == 'E'.ToString() || txtX.Text == 'e'.ToString())
                {
                    holder = 4;
                }
                if (txtX.Text == 'F'.ToString() || txtX.Text == 'f'.ToString())
                {
                    holder = 5;
                }
                if (txtX.Text == 'G'.ToString() || txtX.Text == 'g'.ToString())
                {
                    holder = 6;
                }
                if (txtX.Text == 'H'.ToString() || txtX.Text == 'h'.ToString())
                {
                    holder = 7;
                }
                if (txtX.Text == 'I'.ToString() || txtX.Text == 'i'.ToString())
                {
                    holder = 8;
                }
                if (txtX.Text == 'J'.ToString() || txtX.Text == 'j'.ToString())
                {
                    holder = 9;
                }

                if (holder == 10)
                {
                    lblDirections.Text = "Please input a Possible Position";
                    return;
                }

                /*************************************************************************************/

                if (holdery < 0 || holdery > 9)
                {
                    lblDirections.Text = "Please input a Possible Position";
                    return;
                }

                /*****************************************************************************************/

                if (radioLeft.Checked == true)
                {
                    holderrotation = 1;
                }

                if (radioRight.Checked == true)
                {
                    holderrotation = 3;
                }

                if (radioUp.Checked == true)
                {
                    holderrotation = 2;
                }

                if (radioDown.Checked == true)
                {
                    holderrotation = 4;
                }

                if (holderrotation == 0)
                {
                    lblDirections.Text = "Please select a direction";
                    return;
                }

                int check;
                check = player.setFive(holder, holdery, holderrotation);

                if (check == 1)
                {
                    lblDirections.Text = "Placement failed, please select another position";
                    return;
                }
                else
                {
                    butship1.Visible = false;
                    lblDirections.Text = "Please place the BattleShip";
                }
            }
            catch
            {
                lblDirections.Text = "Please enter input";
            }


        }

        private void butship2_Click(object sender, EventArgs e)
        {

            try
            {
                int holder = 10;
                int holdery = int.Parse(txtY.Text);
                int holderrotation = 0;
                holdery = holdery - 1;


                if (txtX.Text == "A".ToString() || txtX.Text == 'a'.ToString())
                {
                    holder = 0;
                }

                if (txtX.Text == 'B'.ToString() || txtX.Text == 'b'.ToString())
                {
                    holder = 1;
                }

                if (txtX.Text == 'C'.ToString() || txtX.Text == 'c'.ToString())
                {
                    holder = 2;
                }
                if (txtX.Text == 'D'.ToString() || txtX.Text == 'd'.ToString())
                {
                    holder = 3;
                }
                if (txtX.Text == 'E'.ToString() || txtX.Text == 'e'.ToString())
                {
                    holder = 4;
                }
                if (txtX.Text == 'F'.ToString() || txtX.Text == 'f'.ToString())
                {
                    holder = 5;
                }
                if (txtX.Text == 'G'.ToString() || txtX.Text == 'g'.ToString())
                {
                    holder = 6;
                }
                if (txtX.Text == 'H'.ToString() || txtX.Text == 'h'.ToString())
                {
                    holder = 7;
                }
                if (txtX.Text == 'I'.ToString() || txtX.Text == 'i'.ToString())
                {
                    holder = 8;
                }
                if (txtX.Text == 'J'.ToString() || txtX.Text == 'j'.ToString())
                {
                    holder = 9;
                }

                if (holder == 10)
                {
                    lblDirections.Text = "Please input a Possible Position";
                    return;
                }

                /*************************************************************************************/

                if (holdery < 0 || holdery > 9)
                {
                    lblDirections.Text = "Please input a Possible Position";
                    return;
                }

                /*****************************************************************************************/

                if (radioLeft.Checked == true)
                {
                    holderrotation = 1;
                }

                if (radioRight.Checked == true)
                {
                    holderrotation = 3;
                }

                if (radioUp.Checked == true)
                {
                    holderrotation = 2;
                }

                if (radioDown.Checked == true)
                {
                    holderrotation = 4;
                }

                if (holderrotation == 0)
                {
                    lblDirections.Text = "Please select a direction";
                    return;
                }

                int check;
                check = player.setFour(holder, holdery, holderrotation);

                if (check == 1)
                {
                    lblDirections.Text = "Placement failed, please select another position";
                    return;
                }
                else
                {
                    butship2.Visible = false;
                    lblDirections.Text = "Please place the Crusier";
                }
            }
            catch
            {
                lblDirections.Text = "Please enter input";
            }
        }

        private void butship3_Click(object sender, EventArgs e)
        {
            try
            {
                int holder = 10;
                int holdery = int.Parse(txtY.Text);
                int holderrotation = 0;
                holdery = holdery - 1;


                if (txtX.Text == "A".ToString() || txtX.Text == 'a'.ToString())
                {
                    holder = 0;
                }

                if (txtX.Text == 'B'.ToString() || txtX.Text == 'b'.ToString())
                {
                    holder = 1;
                }

                if (txtX.Text == 'C'.ToString() || txtX.Text == 'c'.ToString())
                {
                    holder = 2;
                }
                if (txtX.Text == 'D'.ToString() || txtX.Text == 'd'.ToString())
                {
                    holder = 3;
                }
                if (txtX.Text == 'E'.ToString() || txtX.Text == 'e'.ToString())
                {
                    holder = 4;
                }
                if (txtX.Text == 'F'.ToString() || txtX.Text == 'f'.ToString())
                {
                    holder = 5;
                }
                if (txtX.Text == 'G'.ToString() || txtX.Text == 'g'.ToString())
                {
                    holder = 6;
                }
                if (txtX.Text == 'H'.ToString() || txtX.Text == 'h'.ToString())
                {
                    holder = 7;
                }
                if (txtX.Text == 'I'.ToString() || txtX.Text == 'i'.ToString())
                {
                    holder = 8;
                }
                if (txtX.Text == 'J'.ToString() || txtX.Text == 'j'.ToString())
                {
                    holder = 9;
                }

                if (holder == 10)
                {
                    lblDirections.Text = "Please input a Possible Position";
                    return;
                }

                /*************************************************************************************/

                if (holdery < 0 || holdery > 9)
                {
                    lblDirections.Text = "Please input a Possible Position";
                    return;
                }

                /*****************************************************************************************/

                if (radioLeft.Checked == true)
                {
                    holderrotation = 1;
                }

                if (radioRight.Checked == true)
                {
                    holderrotation = 3;
                }

                if (radioUp.Checked == true)
                {
                    holderrotation = 2;
                }

                if (radioDown.Checked == true)
                {
                    holderrotation = 4;
                }

                if (holderrotation == 0)
                {
                    lblDirections.Text = "Please select a direction";
                    return;
                }

                int check;
                check = player.setThree(holder, holdery, holderrotation);

                if (check == 1)
                {
                    lblDirections.Text = "Placement failed, please select another position";
                    return;
                }
                else
                {
                    butship3.Visible = false;
                    lblDirections.Text = "Please place the Sub";
                }
            }
            catch
            {
                lblDirections.Text = "Please enter input";
            }
        }

        private void butship4_Click(object sender, EventArgs e)
        {
            try
            {
                int holder = 10;
                int holdery = int.Parse(txtY.Text);
                int holderrotation = 0;
                holdery = holdery - 1;


                if (txtX.Text == "A".ToString() || txtX.Text == 'a'.ToString())
                {
                    holder = 0;
                }

                if (txtX.Text == 'B'.ToString() || txtX.Text == 'b'.ToString())
                {
                    holder = 1;
                }

                if (txtX.Text == 'C'.ToString() || txtX.Text == 'c'.ToString())
                {
                    holder = 2;
                }
                if (txtX.Text == 'D'.ToString() || txtX.Text == 'd'.ToString())
                {
                    holder = 3;
                }
                if (txtX.Text == 'E'.ToString() || txtX.Text == 'e'.ToString())
                {
                    holder = 4;
                }
                if (txtX.Text == 'F'.ToString() || txtX.Text == 'f'.ToString())
                {
                    holder = 5;
                }
                if (txtX.Text == 'G'.ToString() || txtX.Text == 'g'.ToString())
                {
                    holder = 6;
                }
                if (txtX.Text == 'H'.ToString() || txtX.Text == 'h'.ToString())
                {
                    holder = 7;
                }
                if (txtX.Text == 'I'.ToString() || txtX.Text == 'i'.ToString())
                {
                    holder = 8;
                }
                if (txtX.Text == 'J'.ToString() || txtX.Text == 'j'.ToString())
                {
                    holder = 9;
                }

                if (holder == 10)
                {
                    lblDirections.Text = "Please input a Possible Position";
                    return;
                }

                /*************************************************************************************/

                if (holdery < 0 || holdery > 9)
                {
                    lblDirections.Text = "Please input a Possible Position";
                    return;
                }

                /*****************************************************************************************/

                if (radioLeft.Checked == true)
                {
                    holderrotation = 1;
                }

                if (radioRight.Checked == true)
                {
                    holderrotation = 3;
                }

                if (radioUp.Checked == true)
                {
                    holderrotation = 2;
                }

                if (radioDown.Checked == true)
                {
                    holderrotation = 4;
                }

                if (holderrotation == 0)
                {
                    lblDirections.Text = "Please select a direction";
                    return;
                }

                int check;
                check = player.setSub(holder, holdery, holderrotation);

                if (check == 1)
                {
                    lblDirections.Text = "Placement failed, please select another position";
                    return;
                }
                else
                {
                    butship4.Visible = false;
                    lblDirections.Text = "Please place the Runner";
                }
            }
            catch
            {
                lblDirections.Text = "Please enter input";
            }
        }

        private void butship5_Click(object sender, EventArgs e)
        {
            try
            {
                int holder = 10;
                int holdery = int.Parse(txtY.Text);
                int holderrotation = 0;
                holdery = holdery - 1;


                if (txtX.Text == "A".ToString() || txtX.Text == 'a'.ToString())
                {
                    holder = 0;
                }

                if (txtX.Text == 'B'.ToString() || txtX.Text == 'b'.ToString())
                {
                    holder = 1;
                }

                if (txtX.Text == 'C'.ToString() || txtX.Text == 'c'.ToString())
                {
                    holder = 2;
                }
                if (txtX.Text == 'D'.ToString() || txtX.Text == 'd'.ToString())
                {
                    holder = 3;
                }
                if (txtX.Text == 'E'.ToString() || txtX.Text == 'e'.ToString())
                {
                    holder = 4;
                }
                if (txtX.Text == 'F'.ToString() || txtX.Text == 'f'.ToString())
                {
                    holder = 5;
                }
                if (txtX.Text == 'G'.ToString() || txtX.Text == 'g'.ToString())
                {
                    holder = 6;
                }
                if (txtX.Text == 'H'.ToString() || txtX.Text == 'h'.ToString())
                {
                    holder = 7;
                }
                if (txtX.Text == 'I'.ToString() || txtX.Text == 'i'.ToString())
                {
                    holder = 8;
                }
                if (txtX.Text == 'J'.ToString() || txtX.Text == 'j'.ToString())
                {
                    holder = 9;
                }

                if (holder == 10)
                {
                    lblDirections.Text = "Please input a Possible Position";
                    return;
                }

                /*************************************************************************************/

                if (holdery < 0 || holdery > 9)
                {
                    lblDirections.Text = "Please input a Possible Position";
                    return;
                }

                /*****************************************************************************************/

                if (radioLeft.Checked == true)
                {
                    holderrotation = 1;
                }

                if (radioRight.Checked == true)
                {
                    holderrotation = 3;
                }

                if (radioUp.Checked == true)
                {
                    holderrotation = 2;
                }

                if (radioDown.Checked == true)
                {
                    holderrotation = 4;
                }

                if (holderrotation == 0)
                {
                    lblDirections.Text = "Please select a direction";
                    return;
                }

                int check;
                check = player.setRunner(holder, holdery, holderrotation);

                if (check == 1)
                {
                    lblDirections.Text = "Placement failed, please select another position";
                    return;
                }
                else
                {
                    butship5.Visible = false;


                    pic0000.Visible = true;             //why pictureboxes. why
                    pic0001.Visible = true;
                    pic0002.Visible = true;
                    pic0003.Visible = true;
                    pic0004.Visible = true;
                    pic0005.Visible = true;
                    pic0006.Visible = true;
                    pic0007.Visible = true;
                    pic0008.Visible = true;
                    pic0009.Visible = true;
                    pic0100.Visible = true;
                    pic0101.Visible = true;
                    pic0102.Visible = true;
                    pic0103.Visible = true;
                    pic0104.Visible = true;
                    pic0105.Visible = true;
                    pic0106.Visible = true;
                    pic0107.Visible = true;
                    pic0108.Visible = true;
                    pic0109.Visible = true;
                    pic0200.Visible = true;
                    pic0201.Visible = true;
                    pic0202.Visible = true;
                    pic0203.Visible = true;
                    pic0204.Visible = true;
                    pic0205.Visible = true;
                    pic0206.Visible = true;
                    pic0207.Visible = true;
                    pic0208.Visible = true;
                    pic0209.Visible = true;
                    pic0300.Visible = true;
                    pic0301.Visible = true;
                    pic0302.Visible = true;
                    pic0303.Visible = true;
                    pic0304.Visible = true;
                    pic0305.Visible = true;
                    pic0306.Visible = true;
                    pic0307.Visible = true;
                    pic0308.Visible = true;
                    pic0309.Visible = true;
                    pic0400.Visible = true;
                    pic0401.Visible = true;
                    pic0402.Visible = true;
                    pic0403.Visible = true;
                    pic0404.Visible = true;
                    pic0405.Visible = true;
                    pic0406.Visible = true;
                    pic0407.Visible = true;
                    pic0408.Visible = true;
                    pic0409.Visible = true;
                    pic0500.Visible = true;
                    pic0501.Visible = true;
                    pic0502.Visible = true;
                    pic0503.Visible = true;
                    pic0504.Visible = true;
                    pic0505.Visible = true;
                    pic0506.Visible = true;
                    pic0507.Visible = true;
                    pic0508.Visible = true;
                    pic0509.Visible = true;
                    pic0600.Visible = true;
                    pic0601.Visible = true;
                    pic0602.Visible = true;
                    pic0603.Visible = true;
                    pic0604.Visible = true;
                    pic0605.Visible = true;
                    pic0606.Visible = true;
                    pic0607.Visible = true;
                    pic0608.Visible = true;
                    pic0609.Visible = true;
                    pic0700.Visible = true;
                    pic0701.Visible = true;
                    pic0702.Visible = true;
                    pic0703.Visible = true;
                    pic0704.Visible = true;
                    pic0705.Visible = true;
                    pic0706.Visible = true;
                    pic0707.Visible = true;
                    pic0708.Visible = true;
                    pic0709.Visible = true;
                    pic0800.Visible = true;
                    pic0801.Visible = true;
                    pic0802.Visible = true;
                    pic0803.Visible = true;
                    pic0804.Visible = true;
                    pic0805.Visible = true;
                    pic0806.Visible = true;
                    pic0807.Visible = true;
                    pic0808.Visible = true;
                    pic0809.Visible = true;
                    pic0900.Visible = true;
                    pic0901.Visible = true;
                    pic0902.Visible = true;
                    pic0903.Visible = true;
                    pic0904.Visible = true;
                    pic0905.Visible = true;
                    pic0906.Visible = true;
                    pic0907.Visible = true;
                    pic0908.Visible = true;
                    pic0909.Visible = true;
                }
            }
            catch
            {
                lblDirections.Text = "Please enter input";
            }
        }

        private void end()                  //GG brother.
        {
            pic0000.Visible = false;            //why pictureboxes. why
            pic0001.Visible = false;
            pic0002.Visible = false;
            pic0003.Visible = false;
            pic0004.Visible = false;
            pic0005.Visible = false;
            pic0006.Visible = false;
            pic0007.Visible = false;
            pic0008.Visible = false;
            pic0009.Visible = false;
            pic0100.Visible = false;
            pic0101.Visible = false;
            pic0102.Visible = false;
            pic0103.Visible = false;
            pic0104.Visible = false;
            pic0105.Visible = false;
            pic0106.Visible = false;
            pic0107.Visible = false;
            pic0108.Visible = false;
            pic0109.Visible = false;
            pic0200.Visible = false;
            pic0201.Visible = false;
            pic0202.Visible = false;
            pic0203.Visible = false;
            pic0204.Visible = false;
            pic0205.Visible = false;
            pic0206.Visible = false;
            pic0207.Visible = false;
            pic0208.Visible = false;
            pic0209.Visible = false;
            pic0300.Visible = false;
            pic0301.Visible = false;
            pic0302.Visible = false;
            pic0303.Visible = false;
            pic0304.Visible = false;
            pic0305.Visible = false;
            pic0306.Visible = false;
            pic0307.Visible = false;
            pic0308.Visible = false;
            pic0309.Visible = false;
            pic0400.Visible = false;
            pic0401.Visible = false;
            pic0402.Visible = false;
            pic0403.Visible = false;
            pic0404.Visible = false;
            pic0405.Visible = false;
            pic0406.Visible = false;
            pic0407.Visible = false;
            pic0408.Visible = false;
            pic0409.Visible = false;
            pic0500.Visible = false;
            pic0501.Visible = false;
            pic0502.Visible = false;
            pic0503.Visible = false;
            pic0504.Visible = false;
            pic0505.Visible = false;
            pic0506.Visible = false;
            pic0507.Visible = false;
            pic0508.Visible = false;
            pic0509.Visible = false;
            pic0600.Visible = false;
            pic0601.Visible = false;
            pic0602.Visible = false;
            pic0603.Visible = false;
            pic0604.Visible = false;
            pic0605.Visible = false;
            pic0606.Visible = false;
            pic0607.Visible = false;
            pic0608.Visible = false;
            pic0609.Visible = false;
            pic0700.Visible = false;
            pic0701.Visible = false;
            pic0702.Visible = false;
            pic0703.Visible = false;
            pic0704.Visible = false;
            pic0705.Visible = false;
            pic0706.Visible = false;
            pic0707.Visible = false;
            pic0708.Visible = false;
            pic0709.Visible = false;
            pic0800.Visible = false;
            pic0801.Visible = false;
            pic0802.Visible = false;
            pic0803.Visible = false;
            pic0804.Visible = false;
            pic0805.Visible = false;
            pic0806.Visible = false;
            pic0807.Visible = false;
            pic0808.Visible = false;
            pic0809.Visible = false;
            pic0900.Visible = false;
            pic0901.Visible = false;
            pic0902.Visible = false;
            pic0903.Visible = false;
            pic0904.Visible = false;
            pic0905.Visible = false;
            pic0906.Visible = false;
            pic0907.Visible = false;
            pic0908.Visible = false;
            pic0909.Visible = false;
        }
            
    }
}
