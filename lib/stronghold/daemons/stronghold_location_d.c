/* binds x,y coordinates on outmap to stronghold id */
/* locations are not to be removed! */

#define SAVEFILE	"/data/stronghold/main_data/STRONGHOLD_LOCATION"
#define VMAP 		"/room/out/outmap"

mapping locations;

query_locations() {
  return locations;
}

string get_stronghold_entrance(int x, int y) {
  int i;
  mixed *coords;
  string file;
  coords = m_values(locations);

  for(i=0; i < sizeof(coords); i++) {
    if(coords[i][0] == x && coords[i][1] == y) {
      file = "/data/stronghold/stronghold_"+m_indices(locations)[i]+"/rooms/entrance";
      if(this_player()->query_wiz()) write("FILE: "+file+"\n");
      if(file_size(file+".c") < 0) return 0;
      return file;
    }
  }
  return 0;
}


status valid_location(int x, int y) {
  string char;
  object env;

  char = VMAP->get_map_char(x,y);
  /* unwanted stronghold locations. a location must also be a loadable vmap room */
  switch(char) {
    case "-": return 0;
    case "|": return 0;
    case "+": return 0;
    case "/": return 0;
    case "\\": return 0;
    case "=": return 0;
    case "?": return 0;
    case "#": return 0;
  }

  env = VMAP->get_room("out", "virtual "+VMAP+" "+x+" "+y);
  if(!env) return 0;

  return 1;
}

void reset_special_marks() {
  int i;
  mixed *coords;
  coords = m_values(locations);

  // no spec marks yet. <- was return;

  for(i=0;i<sizeof(coords);i++) {
    VMAP->set_special_mark(coords[i][0], coords[i][1], "S");
  }
}

void reset(status arg) {
  if(arg) return;
  locations = ([ ]);
  locations += ([ 0 : ({ 0, 0, }), ]);
if(file_size(SAVEFILE+".o") != -1) restore_object(SAVEFILE);
  reset_special_marks();
}

string query_stronghold_id(int x, int y) {
  int i;
  mixed *coords;
  coords = allocate(2);
  coords = m_values(locations);
  for(i=0; i< sizeof(coords); i++) {
    if(coords[i][0] == x && coords[i][1] == y)
      return m_indices(locations)[i];
  }
  return 0;
}

status add_stronghold_location(int stronghold_id, int x, int y) {
  if(query_stronghold_id(x,y)) return 0;
  if(!valid_location(x,y)) return 0;
  locations += ([ stronghold_id : ({x,y,}) ]);
  reset_special_marks();
  save_object(SAVEFILE);
  return 1;
}

status remove_stronghold_location(int id) {
  if(!id) return 0;
  locations -= ([ id ]);
  save_object(SAVEFILE);
  reset_special_marks();
  return 1;
}

int query_exit_dir_x(int id) {
int x;
 if(!locations[id]) return 0;
  x = locations[id][0];
  return x;
}

int query_exit_dir_y(int id) {
int y;
 if(!locations[id]) return 0;
  y = locations[id][1];
  return y;
}


string query_exit_dir(int stronghold_id) {
  int x, y;
/*
  if(this_player()->query_wiz())
    write("Getting stronghold entrace exit dir for stronghold_id "+stronghold_id+".\n");
*/
  if(!locations[stronghold_id]) return 0;
  x = locations[stronghold_id][0];
  y = locations[stronghold_id][1];
  return "virtual "+VMAP+" "+x+" "+y;
}
