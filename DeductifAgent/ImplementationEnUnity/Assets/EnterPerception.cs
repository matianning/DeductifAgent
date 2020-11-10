using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnterPerception : MonoBehaviour
{
    public GameObject Agent;
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
        if(other.name == "Ball")
        {

        }
        else if(other.name == "AgentPurple1" || other.name == "AgentPurple1" || other.name == "AgentBlue1" || other.name == "AgentBlue2"){
            Agent.transform.rotation *= Quaternion.AngleAxis(90, new Vector3(0.0f, 1.0f, 0.0f));
        }
        else
        {
            Agent.transform.rotation *= Quaternion.AngleAxis(180, new Vector3(0.0f, 1.0f, 0.0f));
        }
        
    }
}
