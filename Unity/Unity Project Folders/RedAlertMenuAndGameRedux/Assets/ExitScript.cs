using System;
using System.Security.Cryptography.X509Certificates;
using UnityEngine;
using System.Collections;


public class ExitScript : MonoBehaviour
{
    public GameObject Button;
    private Boolean _hovering;
    private void OnMouseOver()
    {
        if (gameObject)
        {
            _hovering = true;
        }
        if (_hovering)
        {
            if (Input.GetMouseButton(1))
            {
                Application.Quit();
            }
        }
    }

    // Use this for initialization
	void Start () 
    {
	
	}
	
	// Update is called once per frame
	void Update () 
    {
	    if (Input.GetKey(KeyCode.Escape))
	    {
	        Application.Quit();
	    }
    }
}
