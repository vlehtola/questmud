/* New emote system */

#define TPNAME this_player()->query_name()

status emote(string verb, string target, string adverb, string bodypart);
status parse(string str);
string get_adverb(string str);
string get_bodypart(string str);
string get_emote(string str, int query);


get() {
    return 1;
}

drop() { return 1; }

id(str) { return str == "soul_object"; }

long() {
    write("It is transparent.\n");
}

init() {
    add_action("parse", "",1);
}

get_adverb(string str) {
    if (str == "angrily") { return str; }
    if (str == "arrogantly") { return str; }
    if (str == "merrily") { return str; }
}

get_bodypart(string str) {
    /* Approx. alphabetical order, please. */
    if (str == "abdomen") { return str; }
    if (str == "arm") { return str; }
}

string get_emote(string str, int query) {

// With query value 0, we check if emote exists
// It also then returns the 'at' or 'with' etc, that is needed
if (query==0) {
if(str == "hohhoh") { return str+" at"; }
if(str == "wonder") { return str+" about"; }
               }

// As query value 1, an optional default adverb for the emote
// is returned. (Only used if no adverb is specified too)
if (query==1) {
if(str == "hohhoh") { return "merrily"; }
               } 

return 0;
}


status parse(string str) {
string *array;
string verb,target,adverb,bodypart;
int i;

// Debugging
write("'"+str+"' == str\n");
write("'"+lower_case(query_verb())+"' == query_verb()\n");

// Check that the command is an emote, else return 0
verb=get_emote(query_verb(),0);
if(!verb) return 0;

// An emote with no string->call it. fe. 'ack'
if(!str) { emote(verb,0,0,0); return 1; }

// Ok, start the inspection of our str
array=explode(str," ");
// Handle 'emote target','emote adverb', 'emote bpart'
for(i=0;i<sizeof(array);i++)         {
if(present(array[i], environment(this_player()))) { target=array[i]; } else 
if(get_adverb(array[i])) { adverb=array[i]; } else 
if(get_bodypart(array[i])) { bodypart=array[i]; } else 
{ write("Invalid adverb. ('"+array[0]+"')\n"); return 1; }
                             }

 
if(!target && bodypart) target=lower_case(TPNAME); 
emote(verb,target,adverb,bodypart); 
return 1;
}

/*****************************************************************/

/* Only the first argument (verb) is cumpulsory, others an be 0's
 * 1 == the verb (fe. 'poke', 'ack at', 'wonder about') 
 * (the s that is seen by third parties is added in this fun)
 * 2 == the target (fe. 'nalle') 
 * 3 == the adverb (fe. 'zen-likely')
 * 4 == the bodypart (fe. 'nose') 
 */

status emote(string verb, string target, string adverb, string bodypart) {

string tmp1, tmp2; // example: tmp1==wonder tmp2==about
object target_ob;
int at_self;

if(!verb) return 1;
sscanf(verb,"%s %s",tmp1, tmp2);
if(target) target_ob=present(target,environment(this_player()));
if(!adverb) adverb=get_emote(tmp1,1);
write("Default adverb: "+adverb+" Tmp1: "+tmp1+"\n");

// Himself itself etc.
if(target == lower_case(this_player()->query_name())) {
at_self=1;
if(this_player()->query_gender()==0) target="itself";
if(this_player()->query_gender()==1) target="himself";
if(this_player()->query_gender()==2) target="herself";
                                                       } 
else { if(target) target=capitalize(target); }

// An emote with no target or other args
if(!target && !adverb && !bodypart) {
write("You "+tmp1+".\n");
say(TPNAME+" "+tmp1+"s.\n");
return 1;
                                     }
// Emote with target only (-> no default adverb has been assigned)
if(target && !adverb && !bodypart) {
if(at_self)
write("You "+verb+" yourself.\n");
  else {
write("You "+verb+" "+target+".\n");
tell_object(target_ob, TPNAME +" "+tmp1+"s "+tmp2+" you.\n");
       }
say(TPNAME +" "+tmp1+"s "+tmp2+" "+target+".\n",target_ob); 
return 1;
                                    }
// Emote with adverb only
if(!target && adverb && !bodypart) {
write("You "+tmp1+" "+adverb+".\n");
say(TPNAME +" "+tmp1+"s "+adverb+".\n"); 
return 1;
                                    }
// Emote with target and adverb only
if(target && adverb && !bodypart) {
if(at_self)
write("You "+verb+" yourself "+adverb+".\n");
  else {
write("You "+verb+" "+target+" "+adverb+".\n");
tell_object(target_ob, TPNAME +" "+tmp1+"s "+tmp2+" you "+adverb+".\n");
       }
say(TPNAME +" "+tmp1+"s "+tmp2+" "+target+" "+adverb+".\n",target_ob); 
return 1;
                                    }
// Emote with target and and bodypart only
if(target && !adverb && bodypart) {
if(at_self) {
target=this_player()->query_possessive();
write("You "+verb+" your "+bodypart+".\n");
            }
  else {
target+="'s";
write("You "+verb+" "+target+" "+bodypart+".\n");
tell_object(target_ob, TPNAME +" "+tmp1+"s "+tmp2+" your "+bodypart+".\n");
       }
say(TPNAME +" "+tmp1+"s "+tmp2+" "+target+" "+bodypart+".\n",target_ob); 
return 1;
                                    }
// Emote with target, adverb and bodypart
if(target && adverb && bodypart) {
if(at_self) {
target=this_player()->query_possessive();
write("You "+verb+" your "+bodypart+" "+adverb+".\n");
            }
  else {
target+="'s";
write("You "+verb+" "+target+" "+bodypart+" "+adverb+".\n");
tell_object(target_ob, TPNAME +" "+tmp1+"s "+tmp2+" your "+bodypart+" "+adverb+".\n");
       }
say(TPNAME +" "+tmp1+"s "+tmp2+" "+target+" "+bodypart+" "+adverb+".\n",target_ob); 
return 1;
                                    }
//
return 1;
}
