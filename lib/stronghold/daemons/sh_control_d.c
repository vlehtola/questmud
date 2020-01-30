/* STRONGHOLD - CONTROL-DAEMON v0.1 */

// DEFINES
#define SAVEDIR "/data/stronghold/main_data/SH_CONTROL_D"
#define SH_DIR "/data/stronghold/stronghold_"
#define COPIER "/stronghold/daemons/copier"
#define BASIC_ROOM "/stronghold/basic/sh_basic_room"
#define OUTMAP "/room/out/outmap"
#define STRONGHOLD_LOCATION_D "/stronghold/daemons/stronghold_location_d"
#define SH_MAIN_D "/stronghold/daemons/sh_main_d"


// VARS
mapping strongholds;

// PROTOS
void add_stronghold(string owner);
void remove_stronghold(int id);
int get_id();
void debug_write(string msg);

reset(arg) {
if(arg)return;
strongholds = ([ ]);
if(file_size(SAVEDIR+".o") != -1) restore_object(SAVEDIR);

}

void debug_write(string msg) {
	tell_object(find_player("astarel"),msg);
}


int get_id() {
	int i;
  i = 1;
  while(file_size(SH_DIR+i) != -1) {
    i += 1;
  }
  return i;
}

void remove_stronghold(int id) {
string dir, start, end;
string *temp;
mixed *list;
int x,y;
  object dest_ob;
  int i;

  if(id == 0) return 0;
  dest_ob = find_object("/data/stronghold/stronghold_"+id+"/daemons/sh_main_d");
  if(dest_ob) { call_other(dest_ob, "???"); destruct(dest_ob); }
  rm("/data/stronghold/stronghold_"+id+"/daemons/sh_main_d.c");
  rm("/data/stronghold/stronghold_"+id+"/daemons/sh_main_d.o");
  rmdir("/data/stronghold/stronghold_"+id+"/daemons");
  dir = "/data/stronghold/stronghold_"+id+"/rooms/";

  temp = m_indices(strongholds);
  for(i = 0; i < sizeof(temp); i++) {
  	if(temp[i] == this_player()->query_real_name() && strongholds[temp[i]] == id ) {
  		strongholds -= ([ temp[i] ]);
  	}
  
}


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
  
  dir = "/data/stronghold/stronghold_"+id+"/buildings/";
  
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
    
  dir = "/data/stronghold/stronghold_"+id+"/offices/";
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
   
  dir = "/data/stronghold/stronghold_"+id+"/yard/";
  
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
  
  rmdir("/data/stronghold/stronghold_"+id);

  x = STRONGHOLD_LOCATION_D->query_exit_dir_x(id);
  y = STRONGHOLD_LOCATION_D->query_exit_dir_y(id);

  OUTMAP->destruct_loaded_room(x, y); 
  STRONGHOLD_LOCATION_D->remove_stronghold_location(id);
  OUTMAP->set_special_mark(x, y, "p");
  STRONGHOLD_LOCATION_D->reset_special_marks();
  OUTMAP->reset_special_marks();
  save_object(SAVEDIR);
  return;
}
	
void add_stronghold(string owner) {
int new_castle_number,xx,yy;
string new_path;

	if(!owner)return;
	
	if(strongholds[owner]) {
		write("You already have a stronghold!\n");
		return;
	}
		
	new_castle_number = get_id();
	
	strongholds += ([owner : new_castle_number]);
	
	xx = environment(this_player())->query_x();
	yy = environment(this_player())->query_y();
  	  	
  	if((!xx && !yy) || !STRONGHOLD_LOCATION_D->add_stronghold_location(new_castle_number, xx, yy)) {
   	 	write("Stronghold must be deployed outdoors.\n");
    		return;
  	}
	
	mkdir(SH_DIR+new_castle_number);
	new_path = SH_DIR+new_castle_number+"/";
	debug_write(":: new_path:"+new_path+"\n");
	mkdir(new_path+"rooms/");
	mkdir(new_path+"yard/");
	mkdir(new_path+"offices/");
	mkdir(new_path+"buildings/");
	mkdir(new_path+"daemons/");
	debug_write(":: Copying file ::\n");
	COPIER->copy_file(SH_MAIN_D+".c",new_path+"daemons/sh_main_d.c");
	COPIER->copy_file(BASIC_ROOM+".c",new_path+"rooms/entrance.c");
	COPIER->copy_file(BASIC_ROOM+".c",new_path+"rooms/room1.c");
	
	if(file_size(new_path+"rooms/entrance.c") == -1) {
		debug_write(":: ERROR! FILE NOT COPIED! ::\n");
		return;
	}	
	new_path = new_path+"rooms/entrance";	
	//call_other(new_path,"add_room_exit","out","/wizards/astarel/workroom");
	call_other(new_path,"set_ruler",owner);
	call_other(new_path,"set_save_file",new_path);
	
	if(!OUTMAP->check_no_walk(OUTMAP->get_map_char(xx-1,yy+1,0,0,0))) {
    	call_other(new_path,"add_room_exit","northwest","outmap: "+xx+" "+yy); }
  	if(!OUTMAP->check_no_walk(OUTMAP->get_map_char(xx,yy+1,0,0,0))) {
    	call_other(new_path,"add_room_exit","north","outmap: "+xx+" "+yy); }
  	if(!OUTMAP->check_no_walk(OUTMAP->get_map_char(xx+1,yy+1,0,0,0))) {
    	call_other(new_path,"add_room_exit","northeast","outmap: "+xx+" "+yy); }
  	if(!OUTMAP->check_no_walk(OUTMAP->get_map_char(xx+1,yy,0,0,0))) {
    	call_other(new_path,"add_room_exit","east","outmap: "+xx+" "+yy); }
  	if(!OUTMAP->check_no_walk(OUTMAP->get_map_char(xx+1,yy-1,0,0,0))) {
    	call_other(new_path,"add_room_exit","southeast","outmap: "+xx+" "+yy); }
  	if(!OUTMAP->check_no_walk(OUTMAP->get_map_char(xx,yy-1,0,0,0))) {
    	call_other(new_path,"add_room_exit","south","outmap: "+xx+" "+yy); }
  	if(!OUTMAP->check_no_walk(OUTMAP->get_map_char(xx-1,yy-1,0,0,0))) {
    	call_other(new_path,"add_room_exit","southwest","outmap: "+xx+" "+yy); }
  	if(!OUTMAP->check_no_walk(OUTMAP->get_map_char(xx-1,yy,0,0,0))) {
    	call_other(new_path,"add_room_exit","west","outmap: "+xx+" "+yy); }
    	call_other(new_path,"add_room_exit","enter",SH_DIR+new_castle_number+"/rooms/room1");
    	call_other(new_path,"add_room_exit","cs","/world/city/cs");
    	call_other(SH_DIR+new_castle_number+"/rooms/room1","add_room_exit","out",SH_DIR+new_castle_number+"/rooms/entrance");
	move_object(this_player(), "/data/stronghold/stronghold_"+new_castle_number+"/rooms/entrance");
  	OUTMAP->destruct_loaded_room(xx,yy);
  	save_object(SAVEDIR);	
}
