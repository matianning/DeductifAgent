using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallController : MonoBehaviour
{
    public AgentController Purple_Agent1;
    public AgentController Purple_Agent2;
    public AgentController Blue_Agent1;
    public AgentController Blue_Agent2;



    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other)
    {
       
        if(other.name == "AgentPurple1")
        {
            Purple_Agent1.HasBall = true;
            this.gameObject.SetActive(false);
        }
       else if (other.name == "AgentPurple2")
        {
            Purple_Agent2.HasBall = true;
            this.gameObject.SetActive(false);
        }
       else if (other.name == "AgentBlue1")
        {
            Blue_Agent1.HasBall = true;
            this.gameObject.SetActive(false);
        }
       else if (other.name == "AgentBlue2")
        {
            Blue_Agent2.HasBall = true;
            this.gameObject.SetActive(false);

        }
        else
        {

        }
       
    }

}
