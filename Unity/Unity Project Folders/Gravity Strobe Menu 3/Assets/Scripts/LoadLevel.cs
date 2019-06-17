using UnityEngine;
using System.Collections;

public class LoadLevel : MonoBehaviour
{


    private float transitionTime;
    public float delayBeforeTransition;

	// Use this for initialization
	void Start ()
	{
	    transitionTime = Time.time + delayBeforeTransition;
	}
	
	// Update is called once per frame
	void Update () {
	    if (Time.time >= transitionTime)
            Application.LoadLevel(1);
	}
}
