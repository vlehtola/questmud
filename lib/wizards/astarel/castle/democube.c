#define LOC_D "/castle/obj/castle_location_d"
#define castle_info "/data/castle/castle_info"
#define OUTMAP "/room/out/outmap"
#define owners "/data/castle/owner_list"

int type, cost;
get() { return 1; }
long() { write("Castlecube, use 'destroy' to demolish your castle here.\n"); return 1; }
short() { return "Demolition kit"; }
id(str) { if(str == "demolition" || str == "kit") return 1; }

compress_owners(int z) {
  string *list, *temp;
  int i;

  list = explode(read_file(owners), "\n");
  rm(owners);

  for(i=0; i<sizeof(list); i++) {
    temp = explode(list[i], ":");
    if(to_int(temp[1]) != z) write_file(owners, list[i]+"\n");
  }
}

destroy() {
  int id, x, y;
  id = environment(this_player())->query_castle_id();
  x = environment(this_player())->query_x();
  y = environment(this_player())->query_y();

  //  write("DEBUG: x: "+x+", y: "+y+"\n");

  
    if(!environment(this_player())->is_entryroom()) {
      write("Go outside first.\n");
      return 1;
    }
    
    //    move_object(this_player(), "/castle/obj/idleroomwhiledestingcastle");
    move_object(this_player(), "/world/city/cs");
    write("Walls around you fall apart.\n");

    if(this_player()->query_wiz()) write("removing castle ID: "+id+"\n");
    rem_dir(id);

    OUTMAP->destruct_loaded_room(x, y);
    LOC_D->remove_castle_location(id);
    OUTMAP->set_special_mark(x, y, "p");
    LOC_D->reset_special_marks();
    OUTMAP->reset_special_marks();

    compress_owners(id);
    write_file(castle_info, ctime()+": ("+this_player()->query_level()+") "+this_player()->query_name()+" destroyed castle ID "+id+"\n");
  
  return 1;
}

rem_dir(id) {
  string list, dir, start, end;
  object dest_ob;
  int i;

  if(id == 0) return 0;
  dir = "/data/castle/castle_"+id+"/";

  list = get_dir(dir);
  for(i=0; i<sizeof(list); i++) {
    sscanf(list[i], "%s.%s", start, end);
    dest_ob = find_object(dir+start);
    if(dest_ob) {
      call_other(dest_ob, "???");
      if(end == "c") destruct(dest_ob);
    }
    rm(dir+list[i]);
  }
  rmdir(dir);
  return 1;
}

init() {
  add_action("destroy", "destroy");
}
