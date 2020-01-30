// this object is used to prove the committed kill. C 2006

string target_short;
string fulltext;
object mob;
int mark_set;

reset(int arg) {
  if(arg) return;
  fulltext = "(empty)";
  target_short = "nobody";
}

set_target_short(string str) {
  target_short = str;
}

id(string str) { return str=="sack"; }
get() { return 1; }

short() { 
  if(query_mark_dead())
    return "A sack containing a loose head";
  else
    return "A sack used to carry loose heads (empty)";
}

long() { write(short()+"\nUse the sack by 'mark'ing the kill target before death.\n"+
	"The head must be loosened immediately upon death so that it won't rot.\n"+
	"Your target is "+target_short+"\n");
}

int mark_mob(string arg) {
  object obj;
  if(arg) obj = present(arg, environment(this_player()) );

  if(!arg || !obj) {
    write("You can't see such a monster present.\n");
    return 1;
  } else if(!obj->query_npc()) {
    write("You can target monsters only.\n");
    return 1;
  }
  if(target_short != obj->short()) {
    write("That is not your target.\n");
    return 1;
  }
  mob = obj;
  write("You mark "+target_short+" as your kill target.\n");
  mark_set = 1;
  return 1;
}

init() {
  add_action("mark_mob", "mark");
}

int query_mark_dead() {
  if (!mob && target_short && mark_set) {
    return 1;
  }
  return 0;
}
