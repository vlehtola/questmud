#define RUNNER "/wizards/jenny/events/battle/runner"
#define MASTER "/wizards/jenny/events/battle/master"
#define ENDIT "/wizards/jenny/events/battle/event_ob"
#define TPQN this_player()->query_name()
#define TP this_player()
object master;
reset(arg){
  if(arg) return;
}

void start_event() {
  write("You start the battle of the champions.\n");
  shout("The master of the wars has arrived into the city!\n"+
        "Come to cs and sign up to participate the WAR!\n");
  master=clone_object("/wizards/jenny/events/battle/master.c");
  move_object(master,"/world/city/cs.c");
  }
 
//tahan valiin declaree winner,exp,deathi,mappingi

void end_event() {
  write("You end the battle of the champions.\n");
  shout("The master of the wars has left our city, the winner was "+winner+"\n");
  }
 
void end() {
  RUNNER->end_event();
}

ender(){
 if(!dead){
    ENDIT->end();
  }
}
