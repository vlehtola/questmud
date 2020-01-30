string *notes;
#define MAX 10

reset() {
 set_light(100);
  if(!notes) notes = allocate(MAX);
}

id(str) { return str == "note"; }
string short() { return "A small note with lots of writings everywhere"; }
void init() {
  add_action("note","note");
}

status failure() {
  write("Usage: note (list|add|remove) [number] [message]\n");
  return 1;
}

status list() {
  int i;
  string tmp;
  write("+------------------ *NOTES* ------------------+\n");
  for(i=0;i<MAX;i++) write("["+(i+1)+"] - "+notes[i]+"\n");
  write("+------------------ *NOTES* ------------------+\n");
  return 1;
}
status note(string str) {
  int num;
  string msg;
  if(!str) return failure();
  if(strlen(str) < 3) return failure();
  if(str[0..3] == "list") return list();
  if(str[0..2] == "add") {
    if(sscanf(str,"add %d %s",num,msg) != 2) return failure();
    num--;
    if(num < 0 || num > (MAX-1)) {
      write("Use numbers 1-"+MAX+" instead.\n");
      return 1;
    }
    notes[num] = msg;
    num++;
    write("Added note "+num+" as: '"+msg+"'.\n");
    return 1;
  }
  if(str[0..5] == "remove") {
    if(sscanf(str,"remove %d",num) != 1) return 0;
    num--;
    if(num < 0 || num > (MAX-1)) {
      write("Use numbers 1-"+MAX+" instead.\n");
      return 1;
    }
    notes[num] = 0;
    num++;
    write("Removed note "+num+".\n");
    return 1;
  }
return failure();
}

query_autoload() { return "wizards/gheldor/wiz/note:"; }
get() { return 1; }
drop() { return 1; }
