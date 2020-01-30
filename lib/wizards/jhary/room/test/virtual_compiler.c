//This virtual compiler 'realizes' a few thousand rooms, without cloning
//all the rooms. Only a few rooms will be cloned, if needed, and the rest
//will be recycled and renamed.
//                    room_bit       link_bit      track_bit
// maybe_a_room           0              0              0
// impassable room        0              1              0
// empty room             1              0              0
// room with rails        1              0              1
// room with link         1              1              0

inherit "/wizards/jhary/std/virtual/v_compiler";
#include "/wizards/jhary/sys/v_compiler.h"

#include "/wizards/jhary/files.h"

#define SAVEFILE HOME("mines")
// a few inline functions

//creates a corridor at coordinates x,y,z
#define set_room(x,y,z)   rooms[z]=set_bit(rooms[z], x+(y)*DEPTH)

//test if there is a corridor at coordinates x,y,z
#define test_room(x,y,z)  test_bit(rooms[z], x+(y)*DEPTH)

//delete the corridor at coordinates x,y,z 
#define clear_room(x,y,z) rooms[z]=clear_bit(rooms[z], x+(y)*DEPTH)

//Add trails or an elevator to coordinates x,y,z
#define set_track(x,y,z)   track[z]=set_bit(track[z], x+(y)*DEPTH)

//test if there is are trails at coordinates x,y,z
#define test_track(x,y,z)  test_bit(track[z], x+(y)*DEPTH)

//delete trails at coordinates x,y,z
#define clear_track(x,y,z) track[z]=clear_bit(track[z], x+(y)*DEPTH)

//create a link to current_level-1
#define set_verbindung(x,y,z)  verbindung[z]=set_bit(verbindung[z], x+(y)*DEPTH)

//is there a link to current_level-1
#define test_verbindung(x,y,z)  test_bit(verbindung[z], x+(y)*DEPTH)

//clear link to current_level-1
#define clear_verbindung(x,y,z) verbindung[z]=clear_bit(verbindung[z],x+(y)*DEPTH)

//create a filename from given coordinates
#define implode_file(x,y,z) sprintf("/wizards/jhary/room/"+"%dx%dx%d",x,y,z)

//check legal borders
#define legal_xyz(x,y,z) (0<=x && x<WIDTH && 0<=y && y<DEPTH && 0<=z && z<=ALTITUDE)

// Interface
void create();
string Validate(string file);
mixed compile_object(string file);
void AddFreeRoom();
mixed CustomizeObject();
int graben(string dir);

// used variables
string* rooms; 
string* track; 
string* verbindung; 
static object* free_rooms; /* Not used rooms */
static mapping object_store;
string p_std_object;
string p_compiler_path;

mixed objects()
{  return object_store;   }

// Implementation...

void create()
{
  ::create();
  p_std_object=HOME("stdroom");
  p_compiler_path=HOME("");
  free_rooms=({});
  object_store=([]);
  if (!restore_object(SAVEFILE)) 
  {
    int i;
    rooms=allocate(ALTITUDE+1);
    verbindung=allocate(ALTITUDE+1);
    track=allocate(ALTITUDE+1);
    for (i=0;i<=ALTITUDE;i++) 
    {
      rooms[i]="";
      verbindung[i]="";
      track[i]="";
    }
  }
}

string Validate(string file)
// check if filename is supported bei VC
{
  int x,y,z;
  file = ::Validate(file);
  if (file && sscanf(file,"mines%dx%dx%d",x,y,z)==3 && legal_xyz(x,y,z))
    return file;
}

mixed compile_object(string file)
// function is called if we need a new room
{
  if (!Validate(file)) return 0;
  free_rooms-=({ 0 });
  if (sizeof(free_rooms)) 
  { // are there unused rooms?
   object ro;
   object *ob;
   int i;
   ro=free_rooms[0];
   free_rooms-=({ free_rooms[0] });
   // move objects to room
   if (pointerp(ob=object_store[file[0..<3]])) 
   {
     for (i=sizeof(ob)-1;i>=0;i--)
      ob[i]->move(ro, M_NOCHECK);
     object_store[file]=0;
   }
   return ro; // choose an empty room and return it
  }
  return ::compile_object(file); // if there isn't a new room, create one
}

void FreeRoom()
// called from exit() in rooms 
{
 object *inv, *liv;
 int i;
 if (!PO) return;
 inv=all_inventory(PO);
 if (sizeof(liv=filter_array(inv, #'living))>1) return;
 if ((i=sizeof(inv-=liv)-1) >= 0) 
 {
   object_store[file_name(PO)[strlen(HOME(""))..<1]]=inv;
   for (;i>=0;i--)
    inv[i]->move(this_object(), M_NOCHECK);
 }
 free_rooms+=({ PO });
}

#define EXIT(dir,x,y,z) \
   if (legal_xyz(x,y,z) && test_room(x,y,z)) \
        PO->add_exit(dir, implode_file(x, y, z));

                                      
                                      
                                                                  
          




      
