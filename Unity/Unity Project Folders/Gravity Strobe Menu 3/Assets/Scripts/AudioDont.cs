using UnityEngine;
using System.Collections;

public class AudioDont : MonoBehaviour {

    void Awake() {
        DontDestroyOnLoad(transform.gameObject);
    }
}
