// A threaded bulletin-board by Nalle for QuestMUD (July '02)

#include <ansi.h>
#define TP this_player()
#define LEADER_D "/daemons/leader_d"
#define HRLINE write(HRSTR+"\n");
#define HRSTR "-------------------------------------------------------------------------------"
#define SAVEFILE "/data/mudboard"

#define THREADMAX 20
#define PLTHREADMAX 3
#define LEVELLIMIT 10
#define MAXLINES 21

mapping m_map,r_map;
static string *m_arr,*r_arr;
static int hr_i,reply,lines;
static string message_body,topic;

// Prototypes

string player_status(object player);
int read(string str);
int new(string str);
int reply(string str);
int remove(string str);
string bold_number(int number);
string bold_string(string str);
string cyan_string(string str);
void message_writer(string str);
void write_message();
string print_reply(int number); // return as string
int board(string str);
int b_help();

// Endof prototypes

/*********/

id(str) {
    return str == "bulletin board" || str == "board" || str == "bulletinboard";
}

long() {
    write("Type 'board help' for information about available commands.\n");
    headers();
}

short() {
    return ("A shiny new bulletin board");
}

get() {
    write("It is secured to the ground.\n");
    return 0;
}

/************/

init() {

if(!mappingp(m_map)) m_map=([]);
if(!mappingp(r_map)) r_map=([]);
 
m_arr=m_indices(m_map);
r_arr=m_indices(r_map);

  add_action("board","board");
  add_action("read","bread");
  add_action("reply","breply");
  add_action("new","bnew");
}

/***********/

reset(arg) {
    if (arg)
        return;

  if(!m_map) m_map = ([ ]);
  if(!r_map) r_map = ([ ]);

 if(!restore_object(SAVEFILE)) save_object(SAVEFILE); 
}

/**********/

int board(string str) {
string tmp;

if(!str) { write("Try 'board help'.\n"); return 1; }

if(str == "help") { b_help(); return 1; }

if(str == "reset" && TP->query_wiz()) { 
write("Resetting board.\n");
m_map=([]); r_map=([]);
m_arr=m_indices(m_map); r_arr=m_indices(r_map);
save_object(SAVEFILE);
return 1; }

if(sscanf(str, "read %s", tmp)) { read(tmp); return 1; }
if(sscanf(str, "new %s", tmp)) { new(tmp); return 1; }
if(sscanf(str, "reply %s", tmp)) { reply(tmp); return 1; }
if(sscanf(str, "remove %s", tmp)) { remove(tmp); return 1; }

write("Unrecognized command. Try 'board help'.\n");
return 1;
}

/**********/

headers() {
int total,n;

// This is here so all boards with the same file stay up to date
restore_object(SAVEFILE); m_arr=m_indices(m_map); r_arr=m_indices(r_map);

total=sizeof(m_arr);

if(!total) { write("No messages.\n"); return 1; }

// Start printing the headers
write("\nThere are a total of "+total+" threads and "+sizeof(r_arr)+ 
      " follow-ups on the board.\n");
HRLINE
for(n=0;n<total;n++)    {
if (!m_map[n,0]) total++; else // To work with removed threads
write((n+1)+
".'"+cyan_string(m_map[n,3])+"' by "+bold_string(m_map[n,0])+
" ("+m_map[n,1]+" "+
m_map[n,2]+")\nPosted on: "+m_map[n,4]+" Follow-ups: "+m_map[n,6]+"\n");
                        }
write("\n");
}

/**********/

string player_status(object player) {

if(!player) player=TP;

if(player->query_wiz())
switch(player->query_wiz()) { 
        case 5: return "<God>";
        case 4: return "<Demi-God>";
        case 3: return "<ArchWizard>";
        case 2: return "<Wizard>";
        case 1: return "<Apprentice Wizard>";
        break;
                        }

if(TP->query_guest()) return "[Guest]";
if(LEADER_D->test_leader(TP->query_name(),TP->query_race())
   && TP->query_race()) return "{Player}";

return "[Player]";
}

/**********/

int read(string str) {
int n,i,x,thread;
string pager_data;
object pager;

if(!str) { write("Syntax: board read <thread #>.\n"); return 1; }

// Check that the wanted thread exists
for(n=0;n<sizeof(m_arr);n++) thread+=(to_int(str)==to_int(m_arr[n])+1); 

if(!thread) { write("No such thread.\n"); return 1; }

pager_data="";
thread=to_int(str);
n=thread-1;

pager_data="\nStarted reading thread "+ cyan_string(to_string(thread))+" ...\n"+
        HRSTR+(n+1)+".'"+cyan_string(m_map[n,3])+"' by "
        +bold_string(m_map[n,0])+" ("+m_map[n,1]+" "+m_map[n,2]+")\n"+
        "Posted on: '"+m_map[n,4]+"' Follow-ups: "+
        m_map[n,6]+"\n"+HRSTR+m_map[n,7]+"\n"+HRSTR;

// Check for replies
if(m_map[n,6])  
if(sizeof(r_arr))       {
for(x=0;x<m_map[n,6];x++)
for(i=0;i<sizeof(r_arr);i++) {
if((x==r_map[i,1])&&(n==r_map[i,0])) 
pager_data+=print_reply(i); 
                             }
                        }

pager_data+="End of thread.\n";

pager = clone_object("/daemons/pager");
pager->move(this_player());
pager->page(pager_data);

return 1;
}

/**********/

int remove(string str) {
int n,i,x,thread;

if(!str) { write("Syntax: board remove <thread #>\n"); return 1; }

// Check that the wanted thread exists
for(n=0;n<sizeof(m_arr);n++) thread+=(to_int(str)==to_int(m_arr[n])+1); 

if(!thread) { write("No such thread.\n"); return 1; }

thread=to_int(str);
n=thread-1;

// Check that we have rights to the thread
if((TP->query_wiz()<3) && (TP->query_name()!=m_map[n,0])) 
        {
write("You do not have access to remove this thread.\n");
return 1;
        }
if(TP->query_level()<500) // +500 wizzes can remove all threads
if ( (TP->query_wiz())  && ((TP->query_level())<(m_map[n,1]))  && 
     (m_map[n,2]!="[Player]")  && (m_map[n,2]!="{Player}")
    )
 { write("You do not have access to remove this thread.\n");
   return 1;
 }
write("Removing thread #"+(n+1)+".\n");
m_map-=([n]);

// Remove replies
for(i=0;i<sizeof(r_arr);i++) 
if(n==r_map[to_int(r_arr[i]),0]) r_map-=([to_int(r_arr[i])]);

// Update arrays
if(!m_map) m_map=([]); if(!r_map) r_map=([]);
m_arr=m_indices(m_map); r_arr=m_indices(r_map);

save_object(SAVEFILE);
}

/**********/

string print_reply(int number) {
int n;
string temp;

n=number;

temp="Reply by "+bold_string(r_map[n,2])+" ("+r_map[n,3]+" "+r_map[n,5]+
") to "+bold_number(r_map[n,0]+1)+".'"+ r_map[n,4]+"'\n"+
"Posted on: '"+r_map[n,6]+"' (Reply #"+(r_map[n,1]+1)+")\n";
temp+=HRSTR+r_map[n,7]+"\n"+HRSTR;

return temp;
}

/**********/

int b_help() {
write("A threaded message board. Available commands :\n");
write("\n");
write("'board help'             - this help\n");
write("'board new <topic>'      - create new thread with 'topic'\n");
write("'board reply <thread #>' - post to a thread\n");
write("'board read <thread #>'  - read a thread\n");
write("'board remove <thread #>'- remove a thread\n");
if(TP->query_wiz())
write("'board reset'            - reset the board\n");
write("\n");
write("The following aliases also exist: 'bnew','breply', 'bread'.\n");
return 1;
}

/**********/

string bold_number(int number) {
if(TP->query_terminal()) 
{ return BOLD+to_string(number)+OFF; }
else { return to_string(number); }
}

/**********/

string bold_string(string str) {
if(TP->query_terminal()) 
{ return BOLD+str+OFF; }
else { return str; }
}

/**********/

string cyan_string(string str) {
if(TP->query_terminal()) 
{ return CYAN_F+str+OFF; }
else { return str; }
}

/**********/

// Create a new thread
int new(string str) {
int i,x;

if(!str) { write("Syntax : board new <topic>\n"); return 1; }

// board's threadmax 
if(sizeof(m_arr)>THREADMAX && !TP->query_wiz()) { 
write("The maximum amount of threads has been exceeded.\n"); return 1;
}

if(TP->query_guest() || TP->query_level()<LEVELLIMIT) {
write("There is a level-limit of "+LEVELLIMIT+" on this board.\n"); 
return 1;
}

// Check the amount of threads started by this player
for(i=0,x=0;i<sizeof(m_arr);i++) 
if(TP->query_name()==m_map[to_int(m_arr[i]),0]) x++;

// limit
if(x>=PLTHREADMAX+(TP->query_level()/30) && !TP->query_wiz()) {
write("You may only start "+(PLTHREADMAX+(TP->query_level()/30))+
        " threads. Remove some older ones.\n"); 
return 1;
}

topic=str; reply=0;
write("Creating thread with the topic '"+bold_string(topic)+"'.\n");
write_message();
return 1;
}

/**********/

// Reply to a thread
int reply(string str) {
int tmp,n,map_place;

if(!str) { write("Syntax : reply <thread number>\n"); return 1; }

// Check that the wanted thread exists
for(n=0;n<sizeof(m_arr);n++) tmp+=(to_int(str)==to_int(m_arr[n])+1); 

if(!tmp) { write("No such thread.\n"); return 1; }

reply=to_int(str);

// To work with removed threads
for(map_place=0;map_place<sizeof(m_arr);map_place++)
if(m_map[m_arr[map_place],0]) if(m_arr[map_place]==str) break;

write("Replying to thread "+str+" with the topic '"+
        bold_string(m_map[reply-1,3])+"'.\n");
write_message();
return 1;
}

/**********/

void send_message() {
int i,n,thread,map_place;

// Give the thread the right number
thread=sizeof(m_arr);

// Get the map_place
for(i=0;i<=sizeof(m_arr);i++)
if(!m_map[i]) map_place=i;

// Check there is a message body, and it's big enough
if((!message_body) || (message_body==""))       {
write("Cancelled.\n"); return;          }

m_map+=([       map_place:
                TP->query_name();
                TP->query_level();
                player_status(TP);
                topic;
                ctime();
                thread;
                0;
                message_body
        ]);

m_arr=m_indices(m_map);

save_object(SAVEFILE);

write("Message posted.\n");
return;
}

/*********/

void reply_message() {
int i,n,thread,reply_number;

// Thread
thread=reply;
thread--;

// Check there is a message body, and it's big enough
if((!message_body) || (message_body==""))       {
write("Cancelled.\n"); return;                  }
/*
if(strlen(message_body)<6)                              {
write("Too short message. Cancelled.\n"); return;       }
 */
reply_number=sizeof(r_arr); // mapping key

r_map+=([       reply_number:
                thread;
                m_map[thread,6]; // # reply
                TP->query_name();
                TP->query_level();
                m_map[thread,3]; // original topic
                player_status(TP);
                ctime();
                message_body
        ]);

m_map[thread,6]++;

r_arr=m_indices(r_map);

save_object(SAVEFILE);

write("Message posted.\n");
return;
}

/*********/

void write_message()
{
  write(
"Type '**' to end and save or '~q' to quit without saving. \n"+
"Try to keep the lines in your messages shorter than the line below.\n"+
"----------------------------------------------------------------------------\n"+
"# ");
  message_body="";
  input_to("message_writer");
  lines=MAXLINES;
  return;
}

/*********/

void message_writer(string str)
{
  // A line limit
  lines--;

  if(!str) str = "";
  if(str == "~q")
  {
    return;
  }
  if(str == "**" || !lines)
  {
    if(!lines)
    write("Maximum amount of lines used, sending partially.\n");
    if(!reply) send_message(); else reply_message();
    return;
  }
  if((strlen(str)+strlen(message_body))>2048)
  {
    write("Message's maximum length exceeded. Sending partially.\n");
    if(!reply) send_message(); else reply_message();
    return;
  }
  if(!message_body)
    message_body = str;
  else
    message_body += "\n"+str;
  write("# ");
  input_to("message_writer");
}

/*********/

