/* job room to divide coding work. //Celtron */
#define SAVEFILE        "/data/job_room"

inherit "room/room";

mapping tasks;
string task_name;

query_task(int i) {
  return tasks[i];
}

list_tasks(string arg) {
  int i, last, counter;
  string picked, str, empty;
  empty = "                                                                     ";
  last = m_sizeof(tasks);
  write("Available tasks:\n");
  for(i=1; i < last ; i++) {
   if(tasks[i]) {
    picked = tasks[i][2];
    if(!picked) picked = "<empty>";
    str = i+". "+tasks[i][0];
    str = str + empty[0..50-strlen(str)]+" ["+picked+"]\n";
    if(tasks[i][0][0..0] != "(" || arg == "all") {
        counter++;
        write(str);
    }
   }
  }
  write("Total of "+counter+" tasks listed.\n");
  return 1;
}

show_info(mixed a) {
  int arg;
  if(!a || sscanf(a, "%d", arg) != 1) return 0;
  if(!tasks[arg]) {
    write("No such task.\n");
    return 1;
  }
  write(tasks[arg][1]);
  if(tasks[arg][2] && tasks[arg][1] != "")
    write("This task is being done by "+tasks[arg][2]+".\n");
  else if (tasks[arg][1] == "")
    write(tasks[arg][2]+".\n");
  return 1;
}

pick_task(mixed a) {
  int arg;
  if(!a || sscanf(a, "%d", arg) != 1) return 0;
  if(!tasks[arg]) {
    write("No such task.\n");
    return 1;
  }
  if(tasks[arg][2]) {
    write("This task is being done by "+tasks[arg][2]+".\n");
    return 1;
  }
  write("You choose to do the '"+tasks[arg][0]+"' task.\n");
  tasks[arg][2] = this_player()->query_name();
  save_object(SAVEFILE);
  return 1;
}

add_task(string name) {
  object ob;
  if(this_player()->query_wiz() < 3) {
    write("Unable.\n");
    return 1;
  }
  if(!name) {
    write("need argument.\n");
    return 1;
  }
  task_name = name;
  write("Enter task description:\n");
  ob = clone_object("/daemons/editor");
  ob->start("make_task",10, this_object());
  return 1;
}     
      
make_task(string str) {
  string tmp;
  if(!str || str == "") return 0;
  write("Task set.\n");
  tmp = allocate(3);
  if(sscanf(task_name, "%s\n", task_name)) { }
  str = "Added on ["+ctime(time())+"] (by "+this_player()->query_name()+")\n"+
        "Subject: "+task_name+"\n" +str;
  tmp = ({ task_name, str, 0, });
  tasks += ([ m_sizeof(tasks) : tmp ]);
  save_object(SAVEFILE);
  write("Task set and saved.\n");
  "/daemons/channel_d"->send_to_channel("wiz", "added a new task to job room: '"+task_name+"'. (this is automated message)\n");
  return 1;
}  

reset_task(string str) {
  int i;
  if(!str || this_player()->query_wiz() < 4) return 0;
  sscanf(str, "%d", i);   
  tasks[i][2] = 0;
  save_object(SAVEFILE);
  write("Reseted. (marked as unpicked)\n");
  return 1;
}

remove_task(string str) {
  int i;
  if(!str || this_player()->query_wiz() < 4) return 0;
  sscanf(str, "%d", i);
  if(!tasks[i]) return -1;
  tasks[i] = ({ "(done)"+tasks[i][0], "", "Completed by "+tasks[i][2] });
  save_object(SAVEFILE);
  write("Removed. (marked as completed)\n");
  return 1;
}

reset(arg) {
  if(arg) return;
  short_desc = "Job room";
  long_desc =
"This is a place where you can get yourself a new task, something to code.\n"+
"Feel free to shuffle through the tasks available and pick yourself one.\n"+
"NOTE: Do not pick anything if you know that you won't be able to do.\n"+
"Available commands:\n"+
"\tlist [all]\n"+
"\tadd <task>\n"+
"\tremove <task>\n"+
"\tinfo <task>\n"+
"\tpick <task>\n"+
"\treset <task>\n";
  add_exit("inn", "/world/city/inn");
  add_exit("event","/room/event_room");
  add_exit("wizg","/world/city/innstabl");
  add_exit("cs","/world/city/cs");
  set_light(3);
  tasks = ([ ]);
  tasks += ([ 0 : ({"null", "none", 0 }) ]);

  // added by Nalle
  move_object(clone_object("/daemons/wizboard"), this_object());

  if(!restore_object(SAVEFILE))
    save_object(SAVEFILE);

}

init() {
  ::init();
  add_action("list_tasks", "list");
  add_action("show_info", "info");
  add_action("pick_task", "pick");
  add_action("add_task", "add");
  add_action("remove_task", "remove");
  add_action("reset_task", "reset");
}
