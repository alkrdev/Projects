using System.Security.Cryptography.X509Certificates;
using UnityEngine;

public class GameCreation : MonoBehaviour {
    public GameObject GroundPiece;
    public GameObject Player;
    public GameObject Wall;

    private readonly int scale = 20;

    private float centerOffset = 5.2f;
    private readonly int gridSize = 16;
    private int swirlAdjust;

    private void Start() {
        
        #region Main Method

        //for (int b = 1; b < gridSize + 1; b++)
        //{
        //    Instantiate(GroundPiece, new Vector3(GroundPiece.transform.position.x + ((b - 1) * scale), 0, GroundPiece.transform.position.z + ((a - 1) * scale)), Quaternion.identity);
        //}

        //#region Walls
        //Instantiate(Wall, new Vector3(-centerOffset, 1, Wall.transform.position.z + ((a - 1) * scale)), Quaternion.Euler(0, 0, 0));
        //Instantiate(Wall, new Vector3(((a - 1) * scale), 1, -centerOffset), Quaternion.Euler(0, -90, 0));
        //Instantiate(Wall, new Vector3((gridSize - 1) * scale + centerOffset, 1, Wall.transform.position.z + ((a - 1) * scale)), Quaternion.Euler(0, -180, 0));
        //Instantiate(Wall, new Vector3(((a - 1) * scale), 1, (gridSize - 1) * scale + centerOffset), Quaternion.Euler(0, -270, 0));
        //#endregion

        #endregion

        GroundPiece.transform.localScale = new Vector3(scale, 1, scale);

        // Player initialization
        Instantiate(Player);

        // Playarea initialization
        for (var a = 1; a < gridSize + 1; a++) {
            Tile((a - 1) * scale, 0);
            if (a == gridSize) {
                for (var b = 1; b < gridSize + 1; b++) {
                    Tile((a - 1) * scale, -(b * scale));
                    if (b == gridSize) {
                        for (var c = gridSize - 1; c > 0; c--) {
                            Tile((c - 1) * scale, -(b * scale));
                            if (c == 1) {
                                for (var d = gridSize - 1; d > 1; d--) {
                                    Tile((c - 1) * scale, -(d * scale));
                                    if (d == 2) {
                                        for (int e = 1; e < gridSize - 2; e++) {
                                            Debug.Log("E = " + e);
                                            Tile(e * scale, -(scale * 2));
                                            if (e == gridSize - 3) {
                                                for (var f = 3; f < gridSize - 1; f++) {
                                                    Debug.Log("F = " + f);
                                                    Tile(scale * (gridSize - 3), -(f * scale));
                                                    if (f == gridSize - 2) {
                                                        for (int g = gridSize - 3; g > 2; g--) {
                                                            Debug.Log("G = " + g);
                                                            Tile((g - 1) * scale, -(gridSize - 2) * scale);
                                                            if (g == 3) {
                                                                for (int h = gridSize - 3; h > 3; h--) {
                                                                    Debug.Log("H = " + h);
                                                                    Tile(2 * scale, -(h * scale));
                                                                    if (h == 4) {
                                                                        for (int i = 3; i < gridSize - 4; i++) {
                                                                            Debug.Log("I = " + i);
                                                                            Tile(scale * i, -(scale * 4));
                                                                            if (i == 4) {
                                                                                Tile(i * scale, -(5 * scale));
                                                                                Debug.Log("LAST");
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    private void Tile(float x, float z) {
        Instantiate(GroundPiece, new Vector3(x, 0, z), Quaternion.identity);
    }
}