#define castle_info "/data/castle/castle_info"
#define OUTMAP "/room/out/outmap"
#define owners "/data/castle/owner_list"

int type, cost;
string label;
get() { return 1; }
long() { write("Creation cube, use 'deploy' to build your castle here.\n"); return 1; }
short() { 
  if(!label) return "Creation cube";
  else { return "Creation cube, type '"+label+"'"; }
}
id(str) { if(str == "creation" || str == "cube") return 1; }
set_type(arg) { type = arg; }
set_cost(arg) { cost = arg; }
set_label(arg) { label = arg; }

deploy() {
  int castle_id, x, y, i;
  string *list, *tmp;
  object ob;

  list = explode(read_file(owners), "\n");
  for(i=0; i<sizeof(list); i++) {
    tmp = explode(list[i], ":");
    if(tmp[0] == this_player()->query_name()) {
      write("You allready have a castle, destroy it first.\n");
      return 1;
    }
  }

  if(!castle_id = call_other("/castle/obj/castle_code", "go_create", type)) return 1;

  ob = clone_object("/castle/obj/masterkey");
  move_object(ob, this_player());

  if(this_player()->query_wiz()) write("ID: "+castle_id+", path: /data/castle/castle_"+castle_id+"\n");
  write("Castle created. You get masterkey also.\n");
  write_file(castle_info, ctime()+" ("+this_player()->query_level()+") "+capitalize(this_player()->query_name())+" bought castle ;"+castle_id+" at "+cost+" bronze\n");
  x = environment(this_player())->query_x();
  y = environment(this_player())->query_y();
  if(this_player()->query_wiz()) write("Outmaps x: "+x+", y: "+y+"\n");
  move_object(this_player(), "/data/castle/castle_"+castle_id+"/entry");
  OUTMAP->destruct_loaded_room(x,y);
  //  destruct(present("creation", this_player()));
  destruct(this_object());
  return 1;
}

init() {
  add_action("deploy", "deploy");
}
