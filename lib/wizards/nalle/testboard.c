// By Nalle for QuestMUD

#include <ansi.h>
#define DATA_FILE "/wizards/nalle/boarddata"
#define TP this_player()
#define LEADER_D "/daemons/leader_d"
#define HRLINE for(hr_i=0;hr_i<39;hr_i++) write("--"); write("\n");

mapping m_map,r_map;
string *m_arr,*r_arr;
int hr_i,reply;
string message_body,topic;

// Prototypes

string player_status(object player);
int read(string str);
int new(string str);
int reply(string str);
string bold_number(int number);
string bold_string(string str);
void message_writer(string str);
void write_message();
void print_reply(int number);
int board(string str);

// Endof prototypes

/*********/

id(str) {
    return str == "bulletin board" || str == "board" || str == "bulletinboard";
}

long() {
    write("Type 'board help' for information about avaiable commands.\n\n");
    headers();
}

short() {
    return ("A bulletin board");
}

get() {
    write("It is secured to the ground.\n");
    return 0;
}

/************/

init() {

m_map=([
0:"Nalle";525;"<Demi-God>";"topic";"04.07.2002";
"ex2d";0;"this is jsut a test\n...a test.\n"
       ]);

if(!mappingp(m_map)) m_map=([]);
if(!mappingp(r_map)) r_map=([]);

m_arr=m_indices(m_map);
r_arr=m_indices(r_map);

    add_action("board","board");
}

/***********/

reset(arg) {
    if (arg)
        return;
//    restore_object("bulletin");
}

/**********/

int board(string str) {
string tmp;

if(!str) { write("Try 'board help'.\n"); return 1; }

if(sscanf(str, "read %s", tmp)) { read(tmp); return 1; }
if(sscanf(str, "new %s", tmp)) { new(tmp); return 1; }
if(sscanf(str, "reply %s", tmp)) { reply(tmp); return 1; }

write("Unrecognized command. Try 'board help'.\n");
return 1;
}

/**********/

headers() {
int total,n;

total=sizeof(m_arr);

if(!total) { write("No messages.\n"); return 1; }

// Start printing the headers
write("There are a total of "+total+" messages on the board.\n");
HRLINE
for(n=0;n<total;n++)    {
write(bold_number((n+1))+
".'"+m_map[m_arr[n],3]+"' by "+bold_string(m_map[m_arr[n],0])+
" ("+m_map[m_arr[n],1]+" "+
m_map[m_arr[n],2]+")\nPosted on: "+m_map[m_arr[n],4]+" Reply code: '"+
m_map[m_arr[n],5]+"' Follow-ups: "+m_map[m_arr[n],6]+"\n");
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
// Lines below not in switch, to make possible future
// mortal statuses easier to implement

/* // Maybe implemented later
if(player->query_guest()) return "[Guest]";
if(LEADER_D->test_leader(player->query_name(),player->query_race())
   && player->query_race()) return "{Player}";
 */

return "[Player]";
}

/**********/

int read(string str) {
int n,i,x,thread;

if(!str) { write("Wrong syntax.\n"); return 1; }

// Check that the wanted thread exists
for(n=0;n<sizeof(m_arr);n++) thread+=(to_int(str)==to_int(m_arr[n])+1); 

if(!thread) { write("No such thread.\n"); return 1; }

thread=to_int(str);
n=thread-1;

write("\nStarted reading thread "+thread+" ...\n");
write(bold_number(n+1)+".'"+
m_map[m_arr[n],3]+"' by "+
bold_string(m_map[m_arr[n],0])+" ("+m_map[m_arr[n],1]+" "+
m_map[m_arr[n],2]+")\n"+
"Posted on: '"+m_map[m_arr[n],4]+"' Reply code: '"+
m_map[m_arr[n],5]+"' Follow-ups: "+m_map[m_arr[n],6]+"\n");

HRLINE
write(m_map[m_arr[n],7]+"\n");
HRLINE

// Check for replies
if(m_map[m_arr[n],6])   
if(sizeof(r_arr))       {
for(x=0;x<m_map[m_arr[n],6];x++)
for(i=0;i<sizeof(r_arr);i++) {
if((x==r_map[r_arr[i],1])&&(thread-1==r_map[r_arr[i],0])) 
write("Reply loyty.\n"); print_reply(i); 
                             }
                        }
return 1;
}

/**********/

void print_reply(int number) {
int n;

n=number;

write(bold_string(r_map[n,2]+"'s")+" ("+r_map[n,3]+" "+r_map[n,5]+
")  reply to "+bold_number(n+1)+".'"+ r_map[n,4]+"'\n"+
"Posted on: '"+r_map[n,6]+"'\n");

HRLINE
write(r_map[n,7]+"\n");
HRLINE
return;
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

// Create a new thread
int new(string str) {

if(!str) { write("Syntax : new <topic>\n"); return 1; }

topic=str;
write("Creating thread with the topic '"+bold_string(topic)+"'.\n");
write_message();
return 1;
}

/**********/

// Reply to a thread
int reply(string str) {
int tmp,n;

if(!str) { write("Syntax : reply <thread number>\n"); return 1; }

// Check that the wanted thread exists
for(n=0;n<sizeof(m_arr);n++) tmp+=(to_int(str)==to_int(m_arr[n])+1); 

if(!tmp) { write("No such thread.\n"); return 1; }

topic=str; reply=1;

write("Replying to thread "+topic+" with the topic '"+
        bold_string(m_map[m_arr[to_int(topic)-1],3])+"'.\n");
write_message();
return 1;
}

/**********/

void send_message() {
int i,n,thread;

// Give the thread the right number
thread=sizeof(m_arr);

// Check there is a message body, and it's big enough
if((!message_body) || (message_body==""))       {
write("Cancelled.\n"); return;          }
if(strlen(message_body)<8)                      {
write("Too short message.\n"); return;  }


m_map+=([       thread:
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

write("Message posted.\n");
return;
}

/*********/

void reply_message() {
int i,n,thread,reply_number;

// Thread
thread=to_int(topic);
thread--;

// Check there is a message body, and it's big enough
if((!message_body) || (message_body==""))       {
write("Cancelled.\n"); return;                  }
if(strlen(message_body)<6)                              {
write("Too short message. Cancelled.\n"); return;       }

reply_number=sizeof(r_arr); // mapping key

m_map[thread,6]++;

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

r_arr=m_indices(r_map);


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
  input_to("message_writer");
  return;
}

/*********/

void message_writer(string str)
{
  if(!str) str = "";
  if(str == "~q")
  {
    return;
  }
  if(str == "**")
  {
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

