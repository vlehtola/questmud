// daemon file that keeps track of the monsters of questlib
// call the functions get_random_monster_filename and get_random_eq_monster_filename if you like.
// this daemons was made for the headhunter quest.
// made by Celtron (Oct 2005)

#define SOURCEFILE	"/wizards/celtron/headhunter_quest/wizards_moblist"
#define NEW_SOURCEFILE	"/wizards/celtron/headhunter_quest/wizards_moblist_new"
#define SAVEFILE	"/wizards/celtron/headhunter_quest/moblist_savefile"
#define LOGFILE		"monster_track_d"
#define PREFIX		"/wizards/"
#define LINES_READ	10	// how many lines are read at one cycle from the sourcelist

// Variables

mapping monsters, eq_monsters;

// Prototypes

string get_random_monster_filename(int level, int eqmob);
string get_random_eq_monster_filename(int level);

void import_data();
object is_valid_monster_file(string filename);
status compare_mob_level(string filename, int level, mapping mobs);

// Code

void reset(int arg) {
  if(arg) return;
  monsters = ([]);
  eq_monsters = ([]);

  if(!restore_object(SAVEFILE)) {
    save_object(SAVEFILE);  
  }
}

// return the monster if valid
object is_valid_monster_file(string filename, int line) {
  object ob;
  string err;
  if (err = catch(ob = clone_object(filename)) )
    log_file(LOGFILE, "Cannot clone "+filename+" (line "+line+"), reason:"+err, 1);
  if(!ob) return 0;
  return ob;
}


// import data from SOURCEFILE
// lineformat: filename.c:inherit..
// DO NOT CALL THIS FUNCTION!
void import_data(int continue_line) {
  int line, level;
  string data, tmp, filename;
  object mob;

  line = 1;
  if(continue_line) {
    line = continue_line;
  } else {
    rm(NEW_SOURCEFILE);
    monsters = ([]);
    eq_monsters = ([]);
  }
  while((data = read_file(SOURCEFILE, line,1)) && (line <= continue_line + LINES_READ)) {
    if(sscanf(data, "%s:%s", filename, tmp) == 2) {
      filename = PREFIX + filename;
      mob = is_valid_monster_file(filename, line);
      if(mob) {
	write_file(NEW_SOURCEFILE, data);
        level = mob->query_level();
        if(mob->query_log()) {
          eq_monsters += ([ filename : level ]);
        } else {
          monsters += ([ filename : level ]);
        }
        destruct(mob);
      } 
    }
    line +=1;
  }  
  if(line <= (continue_line + LINES_READ)) {
    if(save_object(SAVEFILE)) {
      log_file(LOGFILE, "Couldn't save data, rm first.\n", 1);
      if(!rm(SAVEFILE)) log_file(LOGFILE, "Couldn't remove old savefile!\n", 1);
      save_object(SAVEFILE);
    }
    log_file(LOGFILE, "=== DATAMAPPING UPDATED === ("+ctime(time())+")\n", 1);
  } else {
    log_file(LOGFILE, "Line "+to_int(continue_line + LINES_READ)+" and cycling..\n", 1);
    call_out("import_data", 0, continue_line + LINES_READ);
  }
}

string get_random_eq_monster_filename(int level) {
  return get_random_monster_filename(level, 1);
}

status compare_mob_level(string filename, int level, mapping mobs) {
  if(mobs[filename]/5*5 == level /5*5) {
    return 1;
  }
  return 0;
}

// eqmob == 1 for eqmob
string get_random_monster_filename(int level, int eqmob) {
  int i;
  string *files;
  mapping candidates;

  // use filter_mapping to sort out possible candidates
  if(!eqmob) {
    candidates = filter_mapping(monsters, "compare_mob_level", this_object(), level, monsters);
  } else {
    candidates = filter_mapping(eq_monsters, "compare_mob_level", this_object(), level, eq_monsters);
  }
  files = m_indices(candidates);
  if(!sizeof(files)) 
    return 0;
  i = random(sizeof(files));
  return files[i];
}
