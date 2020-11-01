using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AgentController : MonoBehaviour
{
    public GameObject Goal;
    public bool IsEquipeBlue = false;
    public GameObject Ball_First;
    public GameObject Ball;

    private float PerceptionRadius = 6.0f;  //distance pour la perception de la balle pour un agent
    private float ConflitRadius = 1.0f;     //distance pour prendre la balle d'un agent

    private Vector3 BallPosition;
    private Vector3 RunningDirection;
    
    private float RunningSpeed;
    private float IdleSpeed;
    private float maitrise;

    public bool HasBall;
    private Rigidbody rigidBody;
    private float currRotation;
    public GameObject Perception;

    private int nbActions = 5;
    List<bool> PreConditionList;
    //Liste d'objectives
    /*  0:  Si j'ai la balle, et un adversaire devant, alors je l'évite
     *  1:  Si j'ai la balle, alors j'avance jusqu'à le goal
     *  2:  Si je n'ai pas de balle, et un adversaire a un balle qui est devant, alors je l'approche 
     *  3:  Si je n'ai pas de balle, et j'ai vu une balle, alors j'avance vers cette balle
     *  4:  Si je n'ai pas de balle, et personne dans la zone de perception, alors je idle
     */

    public List<AgentController> AutresAgents;
    private float capacity;

    void Start()
    {
        this.RunningDirection = new Vector3(0.0f, 0.0f, 1.0f);
        this.RunningSpeed = Random.Range(2.0f, 3.0f);
        this.IdleSpeed = RunningSpeed * 0.8f;
        this.HasBall = false;
        this.rigidBody = GetComponent<Rigidbody>();
        PreConditionList = new List<bool>();
        for(int i = 0; i < nbActions; i++)
        {
            PreConditionList.Add(false);
        }
        this.capacity = Random.Range(20, 30);
    }
    

    void Update()
    {
        for (int i = 0; i < nbActions; i++)
        {
            PreConditionList[i] = false;
        }
        UpdateBall();
        //*******ETAPE OBSERVATION du monde******** 

        //********ETAPE DELIBERATION********
        float distance = Vector3.Distance(Ball_First.transform.position, transform.position);
        if (!Ball_First.activeSelf) distance = 1000.0f;
        Vector3 dest = Ball_First.transform.position;
        foreach (AgentController a in AutresAgents)
        {
            if (a.HasBall)
            {
                dest = a.transform.position;
            }

        }
        float distance_Ad_Ball = Vector3.Distance(dest, transform.position);


        if (HasBall)
        {
            PreConditionList[0] = true;
        }
        else
        {
           
            if(distance <= PerceptionRadius)
            {
                PreConditionList[3] = true;
            }

            if(distance_Ad_Ball <= PerceptionRadius)
            {
                PreConditionList[2] = true;
                if(distance_Ad_Ball <= ConflitRadius)
                {
                    PreConditionList[1] = true;
                }

            }
        }
        PreConditionList[PreConditionList.Count - 1] = true;

        //********ETAPE EXECUTION********
        for (int i = 0; i < PreConditionList.Count; i++)
        {
            if(PreConditionList[i] == true)
            {
                switch(i){
                    case 0 : RunToTheGoal(); break;
                    case 1 : PrendreLaBalle(); break;
                    case 2 : FindBallAdversaire(); break;
                    case 3 : FindBall();  break;
                    case 4 : Idle();  break;
                    default: break;
                }
                break;
            }
        }
    }

    void UpdateBall()
    {
        if (HasBall) Ball.SetActive(true);
        else Ball.SetActive(false);
    }

    private void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.name == "WallSideA")
        {
            this.currRotation = 180.0f;
        }

        if(collision.gameObject.name == "WallSideB")
        {
            this.currRotation = 180.0f;
        }
    }

    //***************Actions (Name)********************* 
    void Idle()
    {
       // Debug.Log("Idle" + this.name);
        this.currRotation = Random.Range(-180  , 180);
        rigidBody.MovePosition(rigidBody.position + transform.forward * IdleSpeed * Time.deltaTime);
        rigidBody.MoveRotation(rigidBody.rotation * Quaternion.AngleAxis(currRotation * Time.deltaTime, new Vector3(0.0f,1.0f,0.0f)));
    }

    void FindBall()
    {
        //Debug.Log("FindBall" + this.name);
        Vector3 Dir = Ball_First.transform.position - transform.position;
        float angle = Vector3.Angle(Dir.normalized, transform.forward);
        rigidBody.MovePosition(rigidBody.position + transform.forward * RunningSpeed * Time.deltaTime);
        transform.rotation = Quaternion.LookRotation(Dir);
        //rigidBody.MoveRotation(rigidBody.rotation * Quaternion.AngleAxis(angle * Time.deltaTime, new Vector3(0.0f, 1.0f, 0.0f)));
    }

    void RunToTheGoal()
    {
       // Debug.Log("RunToTheGoal" + this.name);
        Vector3 Dir = Goal.transform.position - transform.position;
        float angle = Vector3.Angle(Dir.normalized, transform.forward);
        rigidBody.MovePosition(rigidBody.position + transform.forward * RunningSpeed * Time.deltaTime);
        transform.rotation = Quaternion.LookRotation(Dir);
        //rigidBody.MoveRotation(rigidBody.rotation * Quaternion.AngleAxis(angle * Time.deltaTime, new Vector3(0.0f, 1.0f, 0.0f)));
    }


    void FindBallAdversaire()
    {
       // Debug.Log("FindBallAdversaire" + this.name);
        Vector3 dest = Ball_First.transform.position;
        foreach(AgentController a in AutresAgents)
        {
            if (a.HasBall)
            {
                dest = a.transform.position;
            }
          
        }
        Vector3 Dir = dest - transform.position;
        rigidBody.MovePosition(rigidBody.position + transform.forward * RunningSpeed * Time.deltaTime);
        transform.rotation = Quaternion.LookRotation(Dir);
    }

    void PrendreLaBalle()
    {
        
        float random = Random.Range(0.0f, 100.0f);
        if(random <= this.capacity)
        {
            this.HasBall = true;
            foreach (AgentController a in AutresAgents)
            {
                if (a.HasBall)
                {
                    a.HasBall = false;
                }
            }
        }
        
    }




}
