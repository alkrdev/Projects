using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ROCKPAPERSCISSORS
{
    class Program
    {
        static void Main(string[] args)
        {
            bool playAgain = true;
            CPU cpu = new CPU();

            while (playAgain)
            {
                int scorePlayer = 0;
                int scoreCPU = 0;

                while (scorePlayer < 3 && scoreCPU < 3)
                {
                    string inputPlayer = MakePlayerChoose();

                    switch (new Random().Next(1, 4))
                    {
                        case 1:
                            cpu.ChoseRock();
                            switch (inputPlayer)
                            {
                                case "ROCK":
                                    Draw();
                                    break;
                                case "PAPER":
                                    PlayerWins();
                                    scorePlayer++;
                                    break;
                                case "SCISSORS":
                                    CPUWins();
                                    scoreCPU++;
                                    break;
                            }
                            break;
                        case 2:
                            cpu.ChosePaper();
                            switch (inputPlayer)
                            {
                                case "PAPER":
                                    Draw();
                                    break;
                                case "ROCK":
                                    CPUWins();
                                    scoreCPU++;
                                    break;
                                case "SCISSORS":
                                    PlayerWins();
                                    scorePlayer++;
                                    break;
                            }
                            break;
                        case 3:
                            cpu.ChoseScissors();
                            switch (inputPlayer)
                            {
                                case "SCISSORS":
                                    Draw();
                                    break;
                                case "ROCK":
                                    PlayerWins();
                                    scorePlayer++;
                                    break;
                                case "PAPER":
                                    CPUWins();
                                    scoreCPU++;
                                    break;
                            }
                            break;
                        default:
                            Console.WriteLine("Invalid entry!");
                            break;
                    }

                    ShowScores(scorePlayer, scoreCPU);
                }

                DecideWinner(scorePlayer, scoreCPU);

                playAgain = DecideIfPlayingAgain(playAgain);
            }
        }

        private static string MakePlayerChoose()
        {
            Console.Write("Choose between ROCK, PAPER and SCISSORS:    ");
            return Console.ReadLine().ToUpper();
        }

        private static void ShowScores(int scorePlayer, int scoreCPU) => Console.WriteLine("\n\nSCORES:\tPLAYER:\t{0}\tCPU:\t{1}", scorePlayer, scoreCPU);

        private static bool DecideIfPlayingAgain(bool playAgain)
        {
            Console.WriteLine("Do you want to play again?(y/n)");
            string loop = Console.ReadLine();

            if (loop == "y")
            {
                playAgain = true;
                Console.Clear();
            }
            else if (loop == "n") playAgain = false;
            return playAgain;
        }

        private static void DecideWinner(int scorePlayer, int scoreCPU)
        {
            if (scorePlayer == 3) Console.WriteLine("Player WON!");
            else if (scoreCPU == 3) Console.WriteLine("CPU WON!");
        }

        private static void CPUWins() => Console.WriteLine("CPU WINS!!\n\n");

        private static void Draw() => Console.WriteLine("DRAW!!\n\n");

        private static void PlayerWins() => Console.WriteLine("PLAYER WINS!!\n\n");

    }

    class CPU
    {
        public void ChoseRock() => Console.WriteLine("Computer chose ROCK");
        public void ChosePaper() => Console.WriteLine("Computer chose PAPER");
        public void ChoseScissors() => Console.WriteLine("Computer chose SCISSORS");
    }
}