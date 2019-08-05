﻿using System;
using System.IO;
using System.Net;
using System.Threading;
using System.Windows;
using Google.Apis.Auth.OAuth2;
using Google.Apis.Services;
using Google.Apis.Sheets.v4;
using Google.Apis.Util.Store;

namespace Library
{
    public class GoogleRequest
    {
        private static readonly string[] Scopes = {
            SheetsService.Scope.SpreadsheetsReadonly
        };

        // Initialize the Credential variable
        private UserCredential _credential;

        public SpreadsheetsResource.ValuesResource.GetRequest GoogleRequestInit()
        {
            try
            {
                using (WebClient wc = new WebClient())
                {
                    wc.DownloadFile(URLReturner(File.ReadAllText(@"Client_Secret_Name.txt")), "\\client_secret.json");

                    // Using the .Json file that contains my "Client Secret" - This allows access to data from spreadsheet
                    using (var stream = new FileStream("\\client_secret.json", FileMode.Open, FileAccess.Read,
                        FileShare.Delete, short.MaxValue, FileOptions.DeleteOnClose)) {
                        // Use initialized Credential - Creates file at given location for future reference, so no further logging in is needed
                        _credential = GoogleWebAuthorizationBroker.AuthorizeAsync(
                            GoogleClientSecrets.Load(stream).Secrets, Scopes, "user", CancellationToken.None,
                            new FileDataStore(
                                Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Personal),
                                    ".credentials\\"), true)).Result;
                    }

                    // Start Service, and give application a name
                    SheetsService service = new SheetsService(new BaseClientService.Initializer
                    {
                        HttpClientInitializer = _credential,
                        ApplicationName = "GuideViewer"
                    });

                    // Delete .Json file after usage
                    File.Delete("\\client_secret.json");

                    // Return values from spreadsheets for use in application
                    return service.Spreadsheets.Values.Get("1uLxm0jvmL1_FJNYUJp6YqIezzqrZdjPf2xQGOWYd6ao", "TestSheet!A2:F");
                }
            }
            catch (Exception e)
            {
                MessageBox.Show("Unable to fetch Datagrid Information" + e);
                return null;
            }            

        }

        // Combines .Json filename and link for Client secret retrieval
        private string URLReturner(string name) {
            return $"https://api.myjson.com/bins/{name}.json";
        }
    }
}