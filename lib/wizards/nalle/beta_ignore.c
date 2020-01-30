/* ++Nalle 09 May 2002, parts of code from previous system */ 

int check_ignored(string str);
int check_levelignore(string str);
void list_ignored();
void set_ignore();

cmd_ignore(string str) {

// Check that the player can interact.
if (!this_player()->check_condis()) { return 1; }


// No arguments-> type the list of people ignored.
if(!str) { list_ignored(); return 1; }

else

// There is a string-> handle it
{ set_ignore(str); return 1; }

}



// List the players you are currently ignoring
/********************/

list_ignored() {

int i, n, level;
string *ignore_list;
string tmp;

ignore_list=this_player()->query_ignored();

if (!pointerp(ignore_list)) { 
 ignore_list = allocate(21); 
 for(i=0;i<=20;i++) ignore_list[i]=0;                
                  }


write("You are currently ignoring :\n");

if(ignore_list[0]) write("Players under level " + ignore_list[0] +".\n"); 

for(i=0;i<=20;i++) {
if(ignore_list[i] && i)  { 
if(n) write(", ");
write(capitalize(ignore_list[i])); n++; 
                     }
                   }
  if (!n) { 
             this_player()->set_ignored(ignore_list); 
             write("No one.\n"); 
             return 1; 
          } else {
  write("\nA total of "+n+" players. (Maximum of 20)\n");
  this_player()->set_ignored(ignore_list); 
  return 1;
  }


}


// handle the string -> set/unset ignore
/********************/


set_ignore(str) {
int i, n, slot, none, level;
object ob;
string *ignore_list;
string tmp;

slot=0;

// Load the ignore list
ignore_list=this_player()->query_ignored();

// Initialize the list if it's empty
if (!pointerp(ignore_list)) { 
 ignore_list = allocate(21); 
 for(i=0;i<=20;i++) ignore_list[i]=0;                
                  }

if (sscanf(str, "%s %s",str,tmp) == 2) {
write("Syntax : ignore <player name> or <level>.\n");
return 1;                                      }

// Check&set if level ignore

if(sscanf(str, "%d", level)) {
  if((level<0) || (level>1000))  {
   write("Invalid level.\n");
   return 1;
                                  }

if(level>=this_player()->query_level()) {
  write("You must set level ignore lower than your level.\n");
  return 1;
                                        }
ignore_list[0]=level;

if(level) 
{  write("You now ignore players below level "+ level +".\n"); }
else
{ write("You now have no level ignore.\n"); }
this_player()->set_ignored(ignore_list);
return 1;

                             }
                            

// Check that the player exists, and isn't a wizard or self
ob = find_player(str);
  if (!ob) {
    ob = clone_object("obj/player.c");
    if (!ob->restore_player(str) || str == "logon") {
      write("No such a player.\n");
      destruct(ob);
      return 1;
    }
            }
  if (!ob) {
    write("No such player.\n");
    return 1;
  }
  if (ob->query_wiz() > this_player()->query_wiz()) {
    write("You fail.\n");
    return 1;
  }
  if(ob->query_name()==this_player()->query_name()) {
    write("You cannot ignore yourself.\n");
    return 1;
  }  
 
//The kikkailu with the slots & settings

// Handle unignoring and finding empty slots
for(i=1;i<=20;i++) {
    if (!ignore_list[i]) { slot = i; }
    if (ignore_list[i] == str) {
      write("You no longer ignore " + capitalize(str) + ".\n");
      ignore_list[i] = 0;
      this_player()->set_ignored(ignore_list);
      return 1;
    }
  }

// Handle ignoring    
  if(slot) {
    ignore_list[slot] = str;   
    write("You now ignore "+capitalize(str)+".\n");
    this_player()->set_ignored(ignore_list); 
    return 1;
  }
 write("Your ignorelist is already full.\n");
 return 1;
}


// external call from player.c (!?)
/********************/

query_ignore(string str, object thisman) {
string ignore_list;
object ob;
int i;

ob=find_player(str);

ignore_list=thisman->query_ignored();

if (!pointerp(ignore_list)) {  return 0; }

// Check level ignore
if( ignore_list[0] > ob->query_level() ) { return 1; }

// Check ignore
for(i=0;i<=20;i++) {
if(ignore_list[i] && i) {
if(capitalize(ignore_list[i])==ob->query_name()) return 1;          
     
                        }                    
                   }

return 0;
}

