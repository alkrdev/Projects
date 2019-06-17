public class Character
{
    public string ButtonText
    {
        get { return string.Format("{0}, {1}, {2}", UserName, ClassName, Level); }
    }

    public string UserName { get; set; }

    public string ClassName { get; set; }

    public string Level { get; set; }

    public string Gold { get; set; }

    public string Materials { get; set; }

    public string Profession { get; set; }

    public string Code { get; set; }

    public string BankCode { get; set; }
}
