using UnityEngine;

public class Movement : MonoBehaviour {

    private float speed = 3;

    private Rigidbody rb;

    private void Start()
    {
        rb = GetComponent<Rigidbody>();
    }

    void Update() {
        float moveHorizontal = Input.GetAxis("Horizontal");
        float moveVertical = Input.GetAxis("Vertical");

        Vector3 movement = new Vector3(moveHorizontal, 0, moveVertical);

        rb.AddForce(movement * speed);

        if(Input.GetKeyDown(KeyCode.Space)) {
            rb.velocity = Vector3.zero;
            rb.angularVelocity = Vector3.zero; 
        }
    }
}
