/* The new emote system for QuestMud by Nalle 2.6.2002 */

#include <ansi.h>
#define TPNAME this_player()->query_name()
#define MIUKU "@"+CYAN_F+TPNAME+OFF
#define ALPHA "/daemons/alpha"
#define ALPHA "/daemons/alpha"
#define COLOURS "/cmds/std/_lite"

inherit "/daemons/emote_data";

status emote(string verb, string target, string adverb, string bodypart);
status remoteemote(string verb, string target, string adverb, string bodypart);
status process_cmd(string str);
string get_adverb(string str);
string get_bodypart(string str, object ob);
string get_emote(string str);
string genitalia(string str, object ob);
status list_emotes();
status list_adverbs();

init() {
    add_action("process_cmd", "",1);
    add_action("list_emotes", "emotes");
    add_action("list_adverbs", "adverbs");
}

/****************************************************************/

string get_emote(string str) {
int i;
for(i=0;i<sizeof(e_array);i++) {
if(str==e_array[i]) return e_array[i];
                                  }
return 0;
}

/*******************************************************************/

status process_cmd(string str) {
string verb,target,adverb,bodypart,temp;
string *array;
int i,n;

// Check for emote/adv list queries
if(query_verb()=="emotes") { list_emotes(); return 1; }
if(query_verb()=="adverbs") { list_adverbs(); return 1; }

// Check that the command is an emote, else return 0
verb=get_emote(query_verb());
if(!verb) return 0;

// An emote with no string->call it.
if(!str) { 
           if(!target && e_map[verb,7]) 
           { write("This emote requires a target.\n"); return 1; }
           emote(verb,target,adverb,bodypart);    
           return 1; 
         }

// Ok, start the inspection of our str
if(!str) return 1;
array=explode(str," ");
// Check our stuff and put it in place
for(i=0;i<sizeof(array);i++)         {
if(find_player(array[i])) target=array[i];  else
if(present(array[i],environment(this_player()))) target=array[i]; else  
if(present(array[i],this_player())) target=array[i]; else  
if(get_bodypart(array[i],0)) bodypart=array[i]; else  
if(get_adverb(array[i])) adverb=get_adverb(array[i]); else
{ write("Invalid adverb. ('"+array[i]+"')\n"); return 1; }
                                     }

// Send the emote like a tell if appropriate
if(target)
if(!present(target, environment(this_player())) && find_player(target)) 
{ remoteemote(verb,target,adverb,bodypart); return 1; }

// Check if the emote requires a target (non-0 at e_map[verb,7]) 
if(!target && e_map[verb,7]) 
{ write("This emote requires a target.\n"); return 1; }

emote(verb,target,adverb,bodypart);    

return 1;
}

/*****************************************************************/

/* Only the first argument (verb) is compulsory, others can be 0's
 * 1 == the verb (fe. 'poke', 'ack at', 'wonder about') 
 * (the s that is seen by third parties is added in this fun)
 * 2 == the target (fe. 'nalle') 
 * 3 == the adverb (fe. 'zen-likely')
 * 4 == the bodypart (fe. 'nose') 
 */

status emote(string verb, string target, string adverb, string bodypart) {

object target_ob;
int at_self,pseudo_target,adv;
string prep,bprep,own_ob,own_obs;
string s_adverb,t_adverb,tar_suff;

// Verb is obligatory
if(!verb) return 1;

// Some inits in case
own_ob=""; own_obs=""; s_adverb="";

// Set the target object for says
if(target) target_ob=present(target,environment(this_player())); 
if(target && !target_ob) 
{ target_ob=present(target,this_player()); pseudo_target=2; }

// Load default adverbs, bparts and targets
if(!adverb && e_map[verb,3]) adverb=e_map[verb,3];
if(!bodypart && e_map[verb,4]) bodypart=e_map[verb,4];
if(!target && e_map[verb,5]) { target=e_map[verb,5]; pseudo_target=3; }
if(adverb) adv=1; else adv=0;

// Our pseudotarget action (e_map5/inanimate objects)
if(target) {
if(!target_ob) pseudo_target=3; 
else {
if(!living(target_ob)) bodypart=0;
if(!find_player(target)) pseudo_target=1; else pseudo_target=0;
if(present(target,this_player())) pseudo_target=2;
     }
           }

// If we have no target but a bodypart, this_player is the default
if(!target && bodypart) { target=lower_case(TPNAME); target_ob=this_player(); }

// This is here because a preposition is not obligatory
// And the pseudo_target 3 (from mapping) is much more handy without preps
if(e_map[verb,2]) { prep=" "+e_map[verb,2]+" "; } else { prep=" "; }
if(pseudo_target==3) { prep=" "; bodypart=0; }

// Himself itself etc.
if(target == lower_case(this_player()->query_name())) {
at_self=1;
if(this_player()->query_gender()==0) target="itself";
if(this_player()->query_gender()==1) target="himself";
if(this_player()->query_gender()==2) target="herself";
                                                       } 
else { if(target && !pseudo_target) target=capitalize(target); }

// This is to make say work unaltered with the pseudo-tgts, and 
// make the target short() if an object
if(pseudo_target)       { 
if(target_ob) 
if(present(target,this_player())) {
own_ob=this_player()->query_possessive()+" "; own_obs="your own ";
                                  } else { own_ob=""; own_obs=""; }
if(pseudo_target!=3) {// not a map6 'about this and that' target
target=lower_case(target_ob->short()); 
if(target_ob) if(living(target_ob)) target=target_ob->short(); 
                     }
target_ob=this_player();  // pseudo-target_obs are always this_player() 
                        }

// Remove 'a' or 'an' from in front if 'his'/etc is to be added
if(pseudo_target==2) { sscanf(target,"a %s",target);
sscanf(target,"an %s",target); sscanf(target,"the %s",target); }

// Check the adverb's position from e_map8, and pad the damn things
if(adverb) adv=1; else adv=0; s_adverb=""; t_adverb="";
if(adv) {
if(e_map[verb,8]==1) { s_adverb=" "+adverb; adverb=""; }
if(e_map[verb,8]==2) { if(bodypart) t_adverb=adverb+" ";
                       else t_adverb=" "+adverb; adverb="";
                     }
if(strlen(adverb)) adverb=" "+adverb; else adverb="";
        }

// A final check for gender dependent bodyparts 
if(!target_ob) target_ob=this_player();
if(bodypart) bodypart=get_bodypart(bodypart, target_ob);

// The emote, say the words

if(!target) { prep=""; target=""; }
if(!adv) { s_adverb=""; adverb=""; t_adverb=""; }
if(!bodypart) { bprep=""; bodypart=""; } else 
   if(!e_map[verb,6]) bprep=""; else bprep=e_map[verb,6]+" ";
tar_suff="";

if(at_self) { 
tar_suff="self"; 
if(strlen(bodypart))  {
if(!e_map[verb,6]) { tar_suff=" "; bprep=""; } 
  else { bprep=e_map[verb,6]+" "; tar_suff="self ";}
                      }
write("You "+e_map[verb,0]+s_adverb+prep+"your"+tar_suff+t_adverb+bprep+bodypart+adverb+".\n");
            } else      {
if(strlen(target) && strlen(bodypart)) if (!e_map[verb,6]) tar_suff="'s "; else tar_suff=" ";
write("You "+e_map[verb,0]+s_adverb+prep+own_obs+target+tar_suff+t_adverb+bprep+bodypart+adverb+".\n");

if(strlen(target)) // "" is a string but 0 long
if(!pseudo_target && present(lower_case(target),environment(this_player())))    
{
if(strlen(bodypart)) { 
if(!e_map[verb,6]) { bprep=""; tar_suff="r "; }  else { bprep=e_map[verb,6]+" "; tar_suff=" "; } 
                     } else { bprep=""; tar_suff=""; }
target_ob=present(lower_case(target),environment(this_player()));
tell_object(target_ob, TPNAME +" "+e_map[verb,1]+s_adverb+prep+"you"+tar_suff+t_adverb+bprep+bodypart+adverb+".\n");
                                                                                
}
                        }
if(strlen(bodypart)) {
if(!e_map[verb,6]) { tar_suff="'s "; 
if(at_self){ target=this_player()->query_possessive(); tar_suff=" "; bprep=""; } 
                   } else { bprep=e_map[verb,6]+" "; tar_suff=" "; }   
                     } else 
 { bprep=""; bodypart=""; if(strlen(adverb)) tar_suff=""; else tar_suff=""; }                    

say(TPNAME +" "+e_map[verb,1]+s_adverb+prep+own_ob+target+tar_suff+t_adverb+bprep+bodypart+adverb+".\n",target_ob); 


return 1;
}

/**********************************************************************/

status remoteemote
(string verb, string target, string adverb, string bodypart) {

object target_ob;
string miuku, color_temp;
string prep,bprep,s_adverb,t_adverb,tar_suff;
int adv;
color_temp="";

if(!verb) return 1;
if(!target || (target==lower_case(TPNAME))) return 1;
target_ob=find_player(target);
if(!target_ob) return 1;

// This is here because a preposition is not obligatory
if(e_map[verb,2]) prep=" "+e_map[verb,2]; else prep="";

// Default adverbs and bodyparts (target has to be a player)
if(!adverb && e_map[verb,3]) adverb=e_map[verb,3];
if(!bodypart && e_map[verb,4]) bodypart=e_map[verb,4];

// Capitalize target's name
target=capitalize(target);

// Check the adverb's position from e_map8, and pad the damn things
if(adverb) adv=1; else adv=0; s_adverb=""; t_adverb="";
if(adv) {
if(e_map[verb,8]==1) { s_adverb=" "+adverb; adverb=""; }
if(e_map[verb,8]==2) { t_adverb=adverb+" "; adverb=""; }
if(strlen(adverb)) adverb=" "+adverb; else adverb="";
        }

// Only give a colored miuku to ansi terminals
color_temp=COLOURS->give_color(target_ob, "emote");
if(!strlen(color_temp)) color_temp=CYAN_F;

if(target_ob->query_terminal()) { miuku="@"+color_temp+TPNAME+OFF; }
                           else { miuku="@"+TPNAME; }

// Check if the target is ignoring us
if(target_ob->query_ignore(lower_case(TPNAME))) {
write("You fail to emote to "+target+". (Ignored)\n");
return 1;                                       }

if(!adv) { s_adverb=""; adverb=""; }
if(!bodypart) { bprep=""; bodypart=""; } else
  if(!e_map[verb,6]) bprep=""; else bprep=e_map[verb,6]+" ";
tar_suff=""; prep+=" ";

if(strlen(bodypart)) if (!e_map[verb,6]) tar_suff="'s "; else tar_suff=" ";
write("Sent: You "+e_map[verb,0]+s_adverb+prep+target+tar_suff+t_adverb+bprep+bodypart+adverb+".\n");

if(strlen(bodypart)) { 
if(!e_map[verb,6]) { bprep=""; tar_suff="r "; }  else { bprep=e_map[verb,6]+" "; tar_suff=" "; } 
                     } else { bprep=""; tar_suff=""; }
tell_object(target_ob, miuku +" "+e_map[verb,1]+s_adverb+prep+"you"+tar_suff+t_adverb+bprep+bodypart+adverb+".\n");

return 1;
}

/***********************************************************************/

/* Matching */ // 3 first
string match_string(string str, string *verbs) {
  int alpha, match, uplimit, downlimit, old_match, i;

// 1st check for perfect match
for(i=0;i<sizeof(verbs);i++) if(str==verbs[i]) return str;

  alpha = ALPHA->get_value(str,3);
  uplimit = sizeof(verbs);
  downlimit = 0; old_match = 1;

  /* binaarihakusysteemi */
  while(match != old_match) {
    old_match = match;
    match = ALPHA->get_value(verbs[(downlimit+uplimit)/2], 3);
/* // Debuggink
if(this_player()->query_wiz()) 
write("matching.."+verbs[(downlimit+uplimit)/2]+": "+downlimit+"/"+uplimit+", "+match+"("+alpha+")\n");
 */
    if(match == alpha)
      return verbs[(downlimit+uplimit)/2];
    else if(match < alpha)
      downlimit = (downlimit+uplimit)/2;
    else
      uplimit = (downlimit+uplimit)/2;
  }
  return 0;
}

/*****************************************************************/

/* Adverbs */

string get_adverb(string str) {
return match_string(str,adverbs);
}

/* Bodyparts */

string get_bodypart(string str, object ob) {
    /* Approx. alphabetical order, please. */
    if (str == "arm") { return str; }
    if (str == "ankle") { return str; }
    if (str == "back") { return str; }
    if (str == "butt") { return str; }
    if (str == "breasts") { return genitalia(str,ob); }
    if (str == "cheek") { return str; }
    if (str == "chin") { return str; }
    if (str == "crotch") { return str; }
    if (str == "chest") { return str; }
    if (str == "eye") { return str; }
    if (str == "elbow") { return str; }
    if (str == "fingers") { return str; }
    if (str == "finger") { return str; }
    if (str == "foot") { return str; }
    if (str == "groin") { return genitalia(str, ob); }
    if (str == "hair") { return str; }
    if (str == "hand") { return str; }
    if (str == "head") { return str; }
    if (str == "jaw") { return str; }
    if (str == "knee") { return str; }
    if (str == "neck") { return str; }
    if (str == "nose") { return str; }
    if (str == "ribs") { return str; }
    if (str == "shoulder") { return str; }
    if (str == "stomach") { return str; }
    if (str == "toe") { return str; }
    if (str == "tongue") { return str; }
    if (str == "toes") { return str; }
    if (str == "throat") { return str; }
    if (str == "thigh") { return str; }
}

/*************************************************************************/

string genitalia(string str, object ob) {
if(!ob) return str;

 if((ob->query_gender())==1)             {
  if(str=="breasts") return "chest";         
  return "groin";                        }

 if((ob->query_gender())==2)    {
  if(str=="breasts") return "breasts";
  return "crotch";              }

 if((ob->query_gender())==0)    {
  if(str=="breasts") return "chest";
  return "crotch";
                                }

}
  

/****************************************************************/

status list_emotes() {
 int i,n;
 string temp, result;
 object pager;
// Check that he is ok
if(!this_player()->check_condis())  { return 1; } 

result="\nEmotes currently in use :\n\n";
for(i=0;i<sizeof(e_array);i++) {
temp=e_array[i];
while(strlen(temp)<21) temp+=" ";
result+=temp; if(!(++n%3)) result+="\n";
                                  }
if(n%3) result+="\n"; result+="\nA total of "+i+" emotes listed.\n";

pager = clone_object("/daemons/pager");
pager->move(this_player());
pager->page(result);

return 1;
}

/****************************************************************/

status list_adverbs() {
 int i,n;
 string temp, result;
 object pager;
// Check that he is ok
if(!this_player()->check_condis())  { return 1; } 

result="\nAdverbs currently in use :\n\n";
for(i=0;i<sizeof(adverbs);i++) {
temp=adverbs[i];
while(strlen(temp)<21) temp+=" ";
result+=temp; if(!(++n%3)) result+="\n";
                                  }
if(n%3) result+="\n"; result+="\nA total of "+i+" adverbs listed.\n";

pager = clone_object("/daemons/pager");
pager->move(this_player());
pager->page(result);

return 1;
}

/****************************************************************/

