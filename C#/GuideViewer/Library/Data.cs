﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Controls;

namespace Library
{
    public class Data
    {
        // Dictionary to keep track of all CheckBoxes
        public Dictionary<string, List<CheckBox>> CheckboxesDictionary { get; set; }

        // Dictionary to keep track of all bool values of CheckBoxes
        public Dictionary<string, bool> CheckboxesBoolDictionary { get; set; }

        // List of all "Select All" Checkboxes
        public List<Tuple<CheckBox, ListView>> ListViewSelectAllList { get; set; }

        // List of tuples that contain almost identical names
        public List<Tuple<string, string>> NameCompareTuples { get; set; }

        // List of all "Select All" Checkboxes
        public List<CheckBox> SelectAllCheckBoxes { get; set; }

        // List of all Checkboxes
        public List<CheckBox> AllCheckBoxes { get; set; }

        // List of all Listviews
        public List<ListView> ListViews { get; set; }

        public Data()
        {
            CheckboxesDictionary = new Dictionary<string, List<CheckBox>>();
            CheckboxesBoolDictionary = new Dictionary<string, bool>();
            ListViewSelectAllList = new List<Tuple<CheckBox, ListView>>();
            NameCompareTuples = new List<Tuple<string, string>>();
            SelectAllCheckBoxes = new List<CheckBox>();
            AllCheckBoxes = new List<CheckBox>();
            ListViews = new List<ListView>();

            ClearEverything();
        }

        private void ClearEverything()
        {
            // Clear everything
            CheckboxesDictionary.Clear();
            CheckboxesBoolDictionary.Clear();
            ListViewSelectAllList.Clear();
            NameCompareTuples.Clear();
            SelectAllCheckBoxes.Clear();
            AllCheckBoxes.Clear();
            ListViews.Clear();
        }
    }
    public class User
    {
        //List of all skillnames in the game
        public static List<string> SkillNames = new List<string>
        {
            "Total",
            "Attack",
            "Defense",
            "Strength",
            "Constitution",
            "Ranged",
            "Prayer",
            "Magic",
            "Cooking",
            "Woodcutting",
            "Fletching",
            "Fishing",
            "Firemaking",
            "Crafting",
            "Smithing",
            "Mining",
            "Herblore",
            "Agility",
            "Thieving",
            "Slayer",
            "Farming",
            "Runecrafting",
            "Hunter",
            "Construction",
            "Summoning",
            "Dungeoneering",
            "Divination",
            "Invention"
        };

        public static Dictionary<string, int> SkillsDictionary = new Dictionary<string, int>();

        //Storage of  the users data
        public static int[] LoadedSkillLevels = new int[SkillNames.Count];
        public static int[] LoadedSkillExperiences = new int[SkillNames.Count];

        //Combination of the users data
        public static Tuple<string, int, int>[] Levels = new Tuple<string, int, int>[SkillNames.Count];

        //Prerequisites
        public static Tuple<string, string>[] PrerequisiteTuples =
        {
            new Tuple<string, string>("Scorpion Catcher", "Barcrawl Miniquest"),
            new Tuple<string, string>("Nomad's Requiem", "Soul Wars Tutorial"),
            new Tuple<string, string>("Children of Mah", "Koschei's Troubles miniquest"),
            new Tuple<string, string>("While Guthix Sleeps", "Chaos Tunnels: Hunt for Surok miniquest"),
            new Tuple<string, string>("Crocodile Tears", "Tier 3 Menaphos City Reputation"),
            new Tuple<string, string>("Our Man in the North", "Tier 6 Menaphos City Reputation"),
            new Tuple<string, string>("'Phite Club", "Tier 9 Menaphos City Reputation")
        };

        //Defaults
        public static int[] DefaultCbList = new int[512];
        public static int[] DefaultIntArray = DefaultCbList.Select(i => 0).ToArray();
        public static string DefaultIntArrayString = string.Join(",", DefaultIntArray);
    }
}

