using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
// ReSharper disable StringIndexOfIsCultureSpecific.1

namespace LoadReader
{
    public partial class MainWindow {

        static string[] lines;

        public MainWindow() {
            InitializeComponent();

            listView.ItemsSource = ExtractCharacters(Directory.GetFiles(GetFullPath()));
        }

        private static IEnumerable<Character> ExtractCharacters(IEnumerable<string> files) {
            var currentCharacters = new List<Character>();

            foreach (var file in files) {
                lines = File.ReadAllLines(file);  
                currentCharacters.Add(ExtractNewCharacter());
            }

            return currentCharacters;
        }

        private static Character ExtractNewCharacter()
        {
            return FixCurrency(new Character
            {
                UserName = ExtractInformation("Name"),
                ClassName = ExtractInformation("Class"),
                Level = ExtractInformation("Level"),
                Gold = ExtractInformation("Gold"),
                Materials = ExtractInformation("Materials"),
                Profession = ExtractInformation("Profession"),
                Code = ExtractInformation("Code"),
                BankCode = ExtractInformation("Bank"),
            });
        }

        static Character FixCurrency(Character cha)
        {
            string gold = cha.Gold;
            cha.Gold = gold.Substring(0, gold.IndexOf(";"));

            string materials = cha.Materials;
            cha.Materials = materials.Substring(materials.IndexOf("Crafting ") + "Crafting ".Length);
            return cha;
        }

        private static string ExtractInformation(string se) 
            => lines.First(x => x.Contains(se + ": "))
                    .Replace(se + ": ", "")
                    .Replace("\t", "");

        private static string GetFullPath() {
            var documents = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
            const string defaultPath = "\\Warcraft III\\CustomMapData\\TBR Saves\\v1.38\\";
            
            return documents + defaultPath;
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            characterInformation.DataContext = (Character)((Button)sender).DataContext;
            ChangePage();
        }
        private void Back_Click(object sender, RoutedEventArgs e)
        {
            ChangePage();
        }

        void ChangePage()
        {
            characterInformation.Visibility = ToggleVisibility(characterInformation);
            listView.Visibility = ToggleVisibility(listView);

            backButton.IsEnabled = backButton.IsEnabled != true ? true : false;
        }

        private Visibility ToggleVisibility(object obj)
        {
            switch (obj)
            {
                case ContentControl cc:
                    return cc.Visibility == Visibility.Visible ? Visibility.Collapsed : Visibility.Visible;
                case ListView lv:
                    return lv.Visibility == Visibility.Visible ? Visibility.Collapsed : Visibility.Visible;
                default:
                    return Visibility.Visible;
            }
        }
    }   
}
