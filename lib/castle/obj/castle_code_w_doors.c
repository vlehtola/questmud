//#define DEBUG
#define LOC_D "/castle/obj/castle_location_d"
#define outmap "/room/out/outmap"

int *num_rooms, id, i;
string room, castle, castledir, *file, *doors;
mixed *kind, *exits;
mapping owner;

string castle_file = (string)"/castle/castle_list";
string castledir = (string)"/data/castle/castle_";
string owner_list = (string)"/data/castle/owner_list";

// protos

int find_free_id();
int generate_room(int room_num, string kin, string exts, string door);
int generate_room_init(string typ, int room_num, string doors);
int generate_room_desc(string tpe, int room_num);
int generate_room_exit(int room_num, string xits, string doo);
int generate_room_finish(int room_num);

alloc_kiitos(int z) {
  int i;

  num_rooms = allocate(z);
  doors = allocate(z);
  kind = allocate(z);
  exits = allocate(z);

  for(i=0; i<z; i++) {
    kind[i] = allocate(50);
    exits[i] = allocate(50);
  }
}

// reads datafile 'castle_file' into arrays
int parse_file() {
  int z, j, k, n, castles, temp, temp2;
  string temp3;
  n = 0;
  file = explode(read_file(castle_file), "\n");
#ifdef DEBUG
  for(z=0; z<sizeof(file); z++) {
    write("z="+z+": "+file[z]+"\n");
  }
#endif
  sscanf(file[n], "castles: %d", castles);

  alloc_kiitos(castles);

  n++;
  for(j=0; j<castles; j++) {
    sscanf(file[n], "num_rooms[%d] = %d", temp, temp2);
    num_rooms[temp] = temp2;
    n++;
  }
  for(j=0; j<castles; j++) {
    for(k=0; k<num_rooms[j]; k++) {
      sscanf(file[n], "kind[%d][%d] = %s", temp, temp2, temp3);
      kind[temp][temp2] = temp3;
      n++;
    }
  }
  for(j=0; j<castles; j++) {
    for(k=0; k<num_rooms[j]; k++) {
      sscanf(file[n], "exits[%d][%d] = %s", temp, temp2, temp3);
      exits[temp][temp2] = temp3;
      n++;
    }
  }
  for(j=0; j<castles; j++) {
    sscanf(file[n], "doors[%d] = %s", temp, temp3);
    doors[temp] = temp3;
    n++;
  }
  return 1;
}

// generates entryroom for this castle
generate_entry(int z) {
  int num_exits, xx, yy;

  room = castle+"/entry.c";
  xx = environment(this_player())->query_x();
  yy = environment(this_player())->query_y();

  write_file(room, "#include \"room.h\"\n\n");

  write_file(room, "string owner;\nint id, x, y;\n");
  write_file(room, "query_owner() { return owner; }\n");
  write_file(room, "set_owner(arg) { owner = arg; }\n");
  write_file(room, "query_castle_id() { return id; }\n");
  write_file(room, "set_castle_id(arg) { id = arg; }\n");
  write_file(room, "query_x() { return x; }\n");
  write_file(room, "set_x(arg) { x = arg; }\n");
  write_file(room, "query_y() { return y; }\n");
  write_file(room, "set_y(arg) { y = arg; }\n");
  write_file(room, "is_entryroom() { return 1; }\n");

  write_file(room, "reset(arg) {\n  if(arg) return;\n");

  write_file(room, "  x = "+xx+";\n");
  write_file(room, "  y = "+yy+";\n");
  write_file(room, "  owner = \""+this_player()->query_name()+"\";\n");
  write_file(room, "  id = "+z+";\n");

  //  if(!outmap->check_no_walk(outmap->get_map_char(xx-1,yy+1,0,0,0))) {
  //  if(outmap->get_room(0, 0, xx-1, yy+1)) { 

  if(!outmap->check_no_walk(outmap->get_map_char(xx-1,yy+1,0,0,0))) {
    write_file(room, "  add_exit(\"northwest\", \"outmap: "+xx+" "+yy+"\");\n"); }
  if(!outmap->check_no_walk(outmap->get_map_char(xx,yy+1,0,0,0))) {
    write_file(room, "  add_exit(\"north\", \"outmap: "+xx+" "+yy+"\");\n"); }
  if(!outmap->check_no_walk(outmap->get_map_char(xx+1,yy+1,0,0,0))) {
    write_file(room, "  add_exit(\"northeast\", \"outmap: "+xx+" "+yy+"\");\n"); }
  if(!outmap->check_no_walk(outmap->get_map_char(xx+1,yy,0,0,0))) {
    write_file(room, "  add_exit(\"east\", \"outmap: "+xx+" "+yy+"\");\n"); }
  if(!outmap->check_no_walk(outmap->get_map_char(xx+1,yy-1,0,0,0))) {
    write_file(room, "  add_exit(\"southeast\", \"outmap: "+xx+" "+yy+"\");\n"); }
  if(!outmap->check_no_walk(outmap->get_map_char(xx,yy-1,0,0,0))) {
    write_file(room, "  add_exit(\"south\", \"outmap: "+xx+" "+yy+"\");\n"); }
  if(!outmap->check_no_walk(outmap->get_map_char(xx-1,yy-1,0,0,0))) {
    write_file(room, "  add_exit(\"southwest\", \"outmap: "+xx+" "+yy+"\");\n"); }
  if(!outmap->check_no_walk(outmap->get_map_char(xx-1,yy,0,0,0))) {
    write_file(room, "  add_exit(\"west\", \"outmap: "+xx+" "+yy+"\");\n"); }
  write_file(room, "  add_exit(\"enter\", \"/data/castle/castle_"+z+"/room0.c\");\n");
  
  write_file(room, "  set_short(\"Entrace to castle\");\n");
  write_file(room, "  set_long(\"There is a castle looming next to you. Castles perimeter has been\"+\n\"\\ncleared of other terrain, making it as safe as possible. There is moot\"+\n\"\\nsurrounding all but the two big doors allowing entry to the castle.\\n\");");
  
  write_file(room, "\n}");
}

/************************
 * main creation function, call this from castle-creator-object.
 ************************/

int go_create(int type) {
  int c, x, y;

  if(castle_file) parse_file();
  else {
    write("No castlefile, contact Archsin.\n");
    return 1;
  }
  id = find_free_id();
  castle = castledir+id;
  x = environment(this_player())->query_x();
  y = environment(this_player())->query_y();

  // add exit to castle on outmap
  if((!x && !y) || !LOC_D->add_castle_location(id, x, y)) {
    write("Castle must be deployed outdoors.\n");
    return 0;
  }

  // create the directory
  mkdir(castledir+i);
  
  for(c=0; c<num_rooms[type]; c++) {
    generate_room(c, (string)kind[type][c], (string)exits[type][c], doors[type]);
  }

  generate_entry(id);
  
  write_file(owner_list, capitalize(this_player()->query_name())+":"+id+"\n");
  return id;
}

// locates next free castle number
int find_free_id() {
  i = 1;
  while(file_size(castledir+i) != -1) {
    i += 1;
  }
  return i;
}

// builds the actual roomX.c file
generate_room(int room_num, string kin, string exts, string door) {
  generate_room_init(kin, room_num, door);
  generate_room_desc(kin, room_num);
  generate_room_exit(room_num, exts, door);
  generate_room_finish(room_num);
  return 1;
}

int generate_room_init(string typ, int room_num, string doors) {
  string *door_a, dira, dirb, door_id, code;
  int has_door, first, last, a;

  door_a = explode(doors, ",");
  room = castle+"/room"+room_num+".c";

  write_file(room, "inherit \"castle/obj/castle_room_d\";\n");
  for(a=0; a<sizeof(door_a); a++) {
    sscanf(door_a[a], "%d:%d:%s:%s:%d", door_id, first, dira, dirb, last);
    if(first == room_num || last == room_num) has_door = 1;
  }
  if(has_door) write_file(room, "inherit \"room/door\";\n");
  write_file(room, "\n");
  write_file(room, "int castle_id;\n");
  write_file(room, "\n");
  write_file(room, "void init() {\n");
  write_file(room, "  ::init();\n");
  if(has_door) write_file(room, "  door_init();\n");
  write_file(room, "  saveable = 1;\n");
  
  if(typ == "portal") {
    write_file(room, "  add_action(\"portal\", \"enter_portal\");\n");
  }
  if(typ == "healing") {
    write_file(room, "  if(!someone_present) call_out(\"room_heal\", 15, amount);\n");
  }
  write_file(room, "}\n\n");
  write_file(room, "query_castle_id() {\n");  
  write_file(room, "  return castle_id;\n");
  write_file(room, "}\n");
  if(typ == "chestroom") write_file(room, "query_startroom() { return 1; }\n\n");
  write_file(room, "reset(arg) {\n");
  write_file(room, "  if(arg) return;\n");
  write_file(room, "  set_not_out(1);\n");
  write_file(room, "  set_light(3);\n");
  write_file(room, "  property = allocate(1);\n");
  write_file(room, "  property[0] = \"no_summon\";\n");
  write_file(room, "  castle_id = "+id+";\n");
  if(has_door) write_file(room, "  door_reset();\n");
  write_file(room, "  restore_room();\n");
  write_file(room, "  generate_chests();\n");
  write_file(room, "  generate_guards();\n");
  return 1;
}

int generate_room_desc(string tpe, int room_num) {
  string room_file, long, short, *along, temp;
  int i, breaked_at;
  room = castle+"/room"+room_num+".c";
  room_file = "/castle/descs/"+tpe;
  
  short = "missing short desc file";
  long = "missing long desc file.\\n";

  if(file_size(room_file) != -1) {
    temp = read_file(room_file);
    sscanf(temp, "%s\n%s", short, long);
    along = explode(long, "\n");
  }
  write_file(room, "  short_desc = \""+short+"\";\n");
  
  if(sizeof(along) == 0) {
    write_file(room, "  long_desc = \""+long+"\";\n");
    return 1;
  }
  write_file(room, "  long_desc = ");
  for(i=0; i<sizeof(along); i++) {
    write_file(room, "  \""+along[i]+"\"+\n");
  }
  write_file(room, "  \"\\n\";\n");

  return 1;
}

get_code(string target, int did) {
  int tdid, i, tcode;
  string *lines;

  write("DEBUG: target: "+target+", did: "+did+"\n");

  if(file_size(target+".c") == -1) {
    write("DEBUG: filesize == -1, target: "+target+"\n");
    return random(1000000);
  }
  lines = explode(read_file(target+".c"), "\n");
  for(i=0; i<sizeof(lines); i++) {
    sscanf(lines[i], "  set_door_code(%d, %d);", tcode, tdid);
    //write("DEBUG: found matching doorcode, target: "+target+", tcode: "+tcode+", id: "+tdid+"\n");
    if(tdid == did) {
      write("DEBUG: found match, returning '"+tcode+"'\n");
      return tcode;
    }
  }
  write("DEBUG: room not generated yet, target: "+target+"\n");
  //  return random(1000000);
}

int generate_room_exit(int room_num, string xits, string doo) {
  int b, nro, first, last, *door_code, door_id, code;
  string *tem, *tem2, dir, loc, target_room, dir_first, dir_last;
  room = castle+"/room"+room_num+".c";
  tem = explode(xits, ",");
  tem2 = explode(doo, ",");
  door_code = allocate(1000);

  if(room_num == 0) {
    loc = LOC_D->query_exit_dir(id);
    write_file(room, "  add_exit(\"out\", \""+loc+"\");\n");
  }
  
  for(b=0; b<sizeof(tem2); b++) {
    sscanf(tem2[b], "%d:%d:%s:%s:%d", door_id, first, dir_first, dir_last, last);
    
    if(room_num == first) {
      target_room = castle+"/room"+last;
      
      //      if(!door_code[door_id]) door_code[last] = door_code[first] = random(1000000);
      write_file(room, "  set_door_label(\"metal door\", "+door_id+");\n");
      write_file(room, "  set_door_dir(\""+dir_first+"\", \""+target_room+"\", "+door_id+");\n");
      write_file(room, "  set_door_link(\""+target_room+"\", "+door_id+");\n");
      write("---\nDEBUG: now at first, in room: "+room_num+"\n");
      write_file(room, "  set_door_code("+get_code(target_room, door_id)+", "+door_id+");\n");
      write_file(room, "  set_locked(1, "+door_id+");\n");
    }
    if(room_num == last) {
      target_room = castle+"/room"+first;
      
      //      if(!door_code[last]) door_code[first] = door_code[last] = random(1000000);
      write_file(room, "  set_door_label(\"metal door\", "+door_id+");\n");
      write_file(room, "  set_door_dir(\""+dir_last+"\", \""+target_room+"\", "+door_id+");\n");
      write_file(room, "  set_door_link(\""+target_room+"\", "+door_id+");\n");
      write("--\nDEBUG: now at last, in room: "+room_num+"\n");
      write_file(room, "  set_door_code("+get_code(target_room, door_id)+", "+door_id+");\n");
      write_file(room, "  set_locked(1, "+door_id+");\n");
    }
  }

  if(tem[0] == "none") {
    return 1;
  }
  for(b=0; b<sizeof(tem); b++) {
    sscanf(tem[b], "%s:%d", dir, nro);
    write_file(room, "  add_exit(\""+dir+"\", \""+castle+"/room"+nro+".c\");\n");
  }
  return 1;
}

int generate_room_finish(int room_num) {
  room = castle+"/room"+room_num+".c";
  write_file(room, "}\n");
  return 1;
}
