// Nalle

// Increased max_length for rebirthers -- Rag 10.4.04

#define TP this_player()
#define STATUS_MAXLENGTH 16
#define REBIRTH_BONUS 8

/********************/

cmd_status(str) 
{
 int max;

 //Had to create a new variable, ask me for details :) Rag 10.4.04
 max = STATUS_MAXLENGTH;

 if ( TP->query_rebirth() > 1 )
 {
  max += REBIRTH_BONUS;
 }

 if(!str) { syntax(); return 1; }

 if(str=="clear" || str=="reset")
        {
        write("Status cleared.\n");
        TP->set_status(0);
        return 1;
        }

 if(TP->query_wiz()<2 && strlen(str)> max )
        {
        write(  "The maximum length for a status is "+
                max+" characters.\n");
        return 1;
        }

        write("Status set to '"+str+"'.\n");
        TP->set_status(str);

 return 1;
}

/********************/

int syntax()
{
 write("Usage : status < message || > \n");
 return 1;
}
