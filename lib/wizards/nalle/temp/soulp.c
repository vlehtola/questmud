/* Modified for genders: padrone, Oct 22 1990 */
/* Additions and upgrades for soul.c completed on 22.6.1998 by Nalle */
/* Major upgrade and additions to bodyparts/adverbs for soul.c completed
 * on 19.4.2001 by Nalle 
 */

object the_owner;
string cap_name;
string adverb;
string bodypart;
string poss; /* The player's possessive */

get() {
    the_owner = this_player();
    cap_name = call_other(this_player(), "query_name", 0);
    return 1;
}

drop() { return 1; }

id(str) { return str == "soul_object"; }

long() {
    write("It is transparent.\n");
}

ghost() {
    the_owner = this_player();
    cap_name = call_other(this_player(), "query_name", 0);
    return call_other(this_player(), "query_ghost");
}

init() {
    the_owner = this_player();
    cap_name = call_other(this_player(), "query_name", 0);
    poss=this_player()->query_possessive();

    add_action("emotes", "emotes");   
    add_action("adverbs", "adverbs"); 
    add_action("ack", "ack");
    add_action("agree", "agree");
    add_action("ah", "ah");
    add_action("apologize", "apologize");
    add_action("applaud", "applaud");
    add_action("argh", "argh");
    add_action("bark", "bark");
    add_action("beg", "beg");
    add_action("bleed", "bleed");
    add_action("blink", "blink");
    add_action("blush", "blush");
    add_action("boo", "boo");
    add_action("bore", "bore");
    add_action("bored", "bored");  
    add_action("bounce", "bounce");
    add_action("bow", "bow");
    add_action("burp", "burp");  
    add_action("cackle", "cackle");
    add_action("calculate", "calculate");
    add_action("caress", "caress");
    add_action("cheer", "cheer");
    add_action("chuckle", "chuckle");
    add_action("clap", "clap");  
    add_action("click", "click");
    add_action("comfort", "comfort");
    add_action("confuse", "confuse");
    add_action("confused", "confused");
    add_action("contently", "contently");
    add_action("congratulate", "congratulate");
    add_action("cough", "cough");  
    add_action("croak", "croak");  
    add_action("cry", "cry");
    add_action("cuddle", "cuddle");
    add_action("curse", "curse");    
    add_action("curtsey", "curtsey");
    add_action("dance", "dance");
    add_action("disagree", "disagree");
    add_action("dream", "dream");  
    add_action("drool", "drool");
    add_action("eww", "eww");
    add_action("eep", "eep");
    add_action("excuse", "excuse");
    add_action("fart", "fart");
    add_action("fear", "fear");
    add_action("flex", "flex");  
    add_action("flip", "flip");  
    add_action("flirt", "flirt");
    add_action("fondle", "fondle");
    add_action("foretell", "foretell");
    add_action("freeze", "freeze");  
    add_action("french", "french");
    add_action("frown", "frown");  
    add_action("gasp", "gasp");
    add_action("giggle", "giggle");
    add_action("gigglesnort", "gigglesnort");
    add_action("glare", "glare");
    add_action("glug", "glug");
    add_action("greet", "greet");
    add_action("grin", "grin");
    add_action("groan", "groan");
    add_action("grope", "grope");
    add_action("growl", "growl");
    add_action("grr", "grr");  
    add_action("gurgle", "gurgle");
    add_action("hail", "hail");
    add_action("heh", "heh");
    add_action("hiccup", "hiccup");  
    add_action("hmm", "hmm");
    add_action("hmpf", "hmpf");  
    add_action("hmph", "hmph");
    add_action("hooray", "hooray");
    add_action("hug", "hug");  
    add_action("hum", "hum");  
    add_action("kick", "kick");
    add_action("kiss", "kiss");
    add_action("knee", "knee");  
    add_action("laugh", "laugh");
    add_action("lick", "lick");  
    add_action("love", "love");  
    add_action("lust", "lust");
    add_action("mercy", "mercy");  
    add_action("moan", "moan");    
    add_action("mourn", "mourn");
    add_action("mrh", "mrh");
    add_action("muah", "muah");      
    add_action("nibble", "nibble");
    add_action("nod", "nod");
    add_action("nodnod", "nodnod");
    add_action("observe", "observe");
    add_action("ooo", "ooo");  
    add_action("oops", "oops");
    add_action("ouch", "ouch");  
    add_action("pat", "pat");
    add_action("play", "play");
    add_action("poke", "poke");  
    add_action("pout", "pout");
    add_action("puke", "puke");
    add_action("purr", "purr");  
    add_action("puuh", "puuh");    
    add_action("refuse", "refuse");  
    add_action("ruffle", "ruffle");
    add_action("scare", "scare");
    add_action("scratch", "scratch");
    add_action("scream", "scream");
    add_action("shake", "shake");  
    add_action("shiver", "shiver");
    add_action("shrug", "shrug");
    add_action("sigh", "sigh");  
    add_action("sing", "sing");  
    add_action("slap", "slap");
    add_action("slobber", "slobber");
    add_action("smirk", "smirk");
    add_action("smile", "smile");
    add_action("smooch", "smooch");
    add_action("snap", "snap");
    add_action("sneeze", "sneeze");
    add_action("snicker", "snicker");
    add_action("sniff", "sniff");  
    add_action("snore", "snore");    
    add_action("snuggle", "snuggle");
    add_action("spit", "spit");  
    add_action("squeeze", "squeeze");
    add_action("stare", "stare");  
    add_action("strip", "strip");  
    add_action("strut", "strut");  
    add_action("sulk", "sulk");  
    add_action("taunt", "taunt");
    add_action("thank", "thank");
    add_action("think", "think");
    add_action("tickle", "tickle");  
    add_action("tremble", "tremble");
    add_action("tsk", "tsk");
    add_action("twiddle", "twiddle");
    add_action("wait", "wait");
    add_action("wake", "wake");
    add_action("wave", "wave");
    add_action("whine", "whine");  
    add_action("whistle", "whistle");
    add_action("wiggle", "wiggle");  
    add_action("worship", "worship");
    add_action("wink", "wink");
    add_action("yawn", "yawn");    
    add_action("yodel", "yodel");  
}

get_adverb(str) {
    if (str == "angrily") { return str; }
    if (str == "arrogantly") { return str; }
    if (str == "affectionately") { return str; }
    if (str == "awfully") { return str; }
    if (str == "audibly") { return str; }
    if (str == "badly") { return str; }
    if (str == "beautifully") { return str; }
    if (str == "boredly") { return str; }
    if (str == "boldly") { return str; }
    if (str == "brilliantly") { return str; }
    if (str == "briefly") { return str; }
    if (str == "bluntly") { return str; }
    if (str == "bitterly") { return str; }
    if (str == "calmly") { return str; }
    if (str == "cheerfully") { return str; }    
    if (str == "coldly") { return str; }
    if (str == "clearly") { return str; }
    if (str == "closely") { return str; }
    if (str == "comically") { return str; }
    if (str == "cruelly") { return str; }
    if (str == "cutely") { return str; }
    if (str == "decently") { return str; }
    if (str == "deeply") { return str; }
    if (str == "determinedly") { return str; }
    if (str == "diabolically") { return str; }
    if (str == "demonically") { return str; }
    if (str == "dirtily") { return str; }
    if (str == "dignifiedly") { return str; }
    if (str == "disgustingly") { return str; }
    if (str == "drily") { return str; }
    if (str == "dizzily") { return str; }
    if (str == "eerily") { return str; }
    if (str == "elegantly") { return str; }
    if (str == "enthousiastically") { return str; }
    if (str == "endlessly") { return str; }
    if (str == "erotically") { return str; }
    if (str == "evilly") { return str; }
    if (str == "fabulously") { return str; }
    if (str == "flegmatically") { return str; }
    if (str == "fearlessly") { return str; }
    if (str == "fearfully") { return str; }
    if (str == "firmly") { return str; }
    if (str == "fiercefully") { return str; }
    if (str == "frankly") { return str; }
    if (str == "funnily") { return str; }
    if (str == "frenetically") { return str; }
    if (str == "gently") { return str; }
    if (str == "girlishly") { return str; }
    if (str == "gleefully") { return str; }
    if (str == "happily") { return str; }
    if (str == "heartily") { return str; } 
    if (str == "heinously") { return str; }
    if (str == "hellishly") { return str; }
    if (str == "helplessly") { return str; }
    if (str == "hilariously") { return str; }
    if (str == "humbly") { return str; }
    if (str == "hungrily") { return str; }
    if (str == "horribly") { return str; }
    if (str == "hornily") { return str; }
    if (str == "idly") { return str; }
    if (str == "lazily") { return str; }
    if (str == "lovingly") { return str; }
    if (str == "magically") { return str; }
    if (str == "majestically") { return str; }
    if (str == "meanly") { return str; }
    if (str == "mercifully") { return str; }
    if (str == "mercilessly") { return str; }
    if (str == "mildly") { return str; }
    if (str == "mimically") { return str; }
    if (str == "merrily") { return str; }
    if (str == "menacingly") { return str; }
    if (str == "mightily") { return str; }
    if (str == "malevolently") { return str; }
    if (str == "meekly") { return str; }
    if (str == "miserably") { return str; }
    if (str == "mischievously") { return str; }
    if (str == "mockingly") { return str; }
    if (str == "mournfully") { return str; }
    if (str == "monstrously") { return str; }
    if (str == "musically") { return str; }
    if (str == "nicely") { return str; }
    if (str == "neatly") { return str; }
    if (str == "nonchalantly") { return str; }
    if (str == "obscurely") { return str; }
    if (str == "oddly") { return str; }
    if (str == "painfully") { return str; }
    if (str == "powerfully") { return str; }
    if (str == "pitifully") { return str; }
    if (str == "openly") { return str; }
    if (str == "promptly") { return str; }
    if (str == "patiently") { return str; }
    if (str == "pervertedly") { return str; }
    if (str == "philantropically") { return str; }
    if (str == "politely") { return str; }
    if (str == "philosophically") { return str; }
    if (str == "poetically") { return str; }
    if (str == "proudly") { return str; }
    if (str == "protectively") { return str; }
    if (str == "quizzically") { return str; }
    if (str == "quickly") { return str; }
    if (str == "repeatedly") { return str; }
    if (str == "rhetorically") { return str; }
    if (str == "remorsefully") { return str; }
    if (str == "sadly") { return str; }
    if (str == "scornfully") { return str; }
    if (str == "sarcastically") { return str; }
    if (str == "slowly") { return str; }
    if (str == "strangely") { return str; }
    if (str == "sheepishly") { return str; }
    if (str == "sensually") { return str; }
    if (str == "smoothly") { return str; }
    if (str == "sexily") { return str; }
    if (str == "satanically") { return str; }
    if (str == "scornfully") { return str; }
    if (str == "sceptically") { return str; }
    if (str == "shrilly") { return str; }
    if (str == "silently") { return str; }
    if (str == "sternly") { return str; }
    if (str == "skillfully") { return str; }
    if (str == "sinfully") { return str; }
    if (str == "subconsciously") { return str; }
    if (str == "subtly") { return str; }
    if (str == "tunefully") { return str; }
    if (str == "toothlessly") { return str; }
    if (str == "thoughtfully") { return str; }
    if (str == "vengefully") { return str; }
    if (str == "utterly") { return str; }
    if (str == "wholeheartedly") { return str; }
    if (str == "wrongfully") { return str; }
    if (str == "wetly") { return str; }
    if (str == "weirdly") { return str; }
    if (str == "wickedly") { return str; }
    if (str == "wimpily") { return str; }
    if (str == "wistfully") { return str; }
    if (str == "wondrously") { return str; }
    if (str == "wryly") { return str; }
    if (str == "wrathfully") { return str; }
    if (str == "xenophobically") { return str; }
    if (str == "zealously") { return str; }
    if (str == "zen-likely") { return str; }
    if (str == "zymotically") { return str; }
}

get_bodypart(str) {
    /* Approx. alphabetical order, please. */
    if (str == "abdomen") { return str; }
    if (str == "arm") { return str; }
    if (str == "ankle") { return str; }
    if (str == "back") { return str; }
    if (str == "butt") { return str; }
    if (str == "buttocks") { return str; }
    if (str == "breasts") { return genitalia(str); }
    if (str == "cheek") { return str; }
    if (str == "chin") { return str; }
    if (str == "cunt") { return genitalia(str); }
    if (str == "crotch") { return genitalia(str); }
    if (str == "chest") { return str; }
    if (str == "eye") { return str; }
    if (str == "elbow") { return str; }
    if (str == "fingers") { return str; }
    if (str == "finger") { return str; }
    if (str == "foot") { return str; }
    if (str == "groin") { return str; }
    if (str == "hand") { return str; }
    if (str == "head") { return str; }
    if (str == "jaw") { return str; }
    if (str == "knee") { return str; }
    if (str == "neck") { return str; }
    if (str == "nose") { return str; }
    if (str == "penis") { return genitalia(str); }
    if (str == "shoulder") { return str; }
    if (str == "slit") { return genitalia(str); }
    if (str == "stomach") { return str; }
    if (str == "tit") { return genitalia(str); }
    if (str == "tits") { return genitalia(str); }
    if (str == "toe") { return str; }
    if (str == "throat") { return str; }
    if (str == "thigh") { return str; }
    if (str == "toes") { return str; }
}

string genitalia(string str) {
 if((this_player()->query_gender())==1) 
 {
  if(str=="groin") return "groin";
  if(str=="penis") return "penis";
  if(str=="breasts") return "chest";          
  return "penis";                             
 }

 if((this_player()->query_gender())==2) 
 {
  if(str=="slit") return "slit";
  if(str=="cunt") return "cunt";
  if(str=="breasts") return "breasts";
  if(str=="tit") return "tit";          
  if(str=="tits") return "tits";          
  return "slit";                               
 }
 if((this_player()->query_gender())==0) 
 {
  if(str=="breasts") return "chest";
  return "crotch";                                 
 }
}  

emotes() {
    if (ghost())
        return 0;
        write("To list the available emotes type 'help emotes'.\n");
        return 1;
} 

adverbs() {
    if (ghost())
        return 0;
    write("To list the available adverbs and bodyparts type 'help adverbs'.\n");
    return 1;
}


ack(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You ack.\n");
 say(cap_name + " acks.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "thoughtfully"; }
 tell_object(who, cap_name + " acks at you " + adverb + ".\n");
 write("You ack at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " acks at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You ack " + adverb + ".\n");
 say(cap_name + " acks " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " acks at you.\n");
 write("You ack at " + capitalize(str) + ".\n");
 say(cap_name + " acks at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


agree(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You agree.\n");
 say(cap_name + " agrees.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "fully"; }
 tell_object(who, cap_name + " agrees with you " + adverb + ".\n");
 write("You agree with " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " agrees with " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }

    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You agree " + adverb + ".\n");
 say(cap_name + " agrees " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " agrees you.\n");
 write("You agrees with " + capitalize(str) + ".\n");
 say(cap_name + " agrees with " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


ah(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You go 'Ah' in comprehension.\n");
 say(cap_name + " goes 'Ah' in comprehension.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "comprehensively"; }
 tell_object(who, cap_name + " goes 'Ah' at you " + adverb + ".\n");
 write("You go 'Ah' at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " goes 'Ah' at " + capitalize(target) + " " + adverb
+".\n",who);
    return 1;
                                                }

    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You go 'Ah' " + adverb + ".\n");
 say(cap_name + " goes 'Ah' " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " goes 'Ah' at you.\n");
 write("You go 'Ah' at " + capitalize(str) + ".\n");
 say(cap_name + " goes 'Ah' at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


apologize(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You apologize.\n");
 say(cap_name + " apologizes.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "humbly"; }
 tell_object(who, cap_name + " apologizes to you " + adverb + ".\n");
 write("You apologizes to " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " apologizes to " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }

    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You apologize " + adverb + ".\n");
 say(cap_name + " apologizes " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " apologizes to you.\n");
 write("You apologize to " + capitalize(str) + ".\n");
 say(cap_name + " apologizes to " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


applaud(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You applaud.\n");
 say(cap_name + " applauds.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "wholeheartedly"; }
 tell_object(who, cap_name + " applauds at you " + adverb + ".\n");
 write("You applaud at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " applauds at " + capitalize(target) + " " + adverb
+".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You applaud " + adverb + ".\n");
 say(cap_name + " applauds " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " applauds at you.\n");
 write("You applaud at " + capitalize(str) + ".\n");
 say(cap_name + " applauds at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


argh(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You screams 'AARGH'.\n");
 say(cap_name + " screams 'AARGH'.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "hellishly"; }
 tell_object(who, cap_name + " screams 'AARGH' at you " + adverb + ".\n");
 write("You scream 'AARGH'  at " + capitalize(target) + " " + adverb +
 ".\n");
 say(cap_name + " screams 'AARGH'  at " + capitalize(target) + " " +
 adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You scream 'AARGH' " + adverb + ".\n");
 say(cap_name + " screams 'AARGH' " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " screams 'AARGH' at you.\n");
 write("You scream 'AARGH' at " + capitalize(str) + ".\n");
 say(cap_name + " screams 'AARGH' at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


bark(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You start barking like a dog.\n");
 say(cap_name + " starts barking like a dog.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "rabidly"; }
 tell_object(who, cap_name + " barks at you " + adverb + ".\n");
 write("You bark at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " bark at " + capitalize(target) + " " + adverb
+".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You bark " + adverb + ".\n");
 say(cap_name + " barks " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " barks at you.\n");
 write("You bark at " + capitalize(str) + ".\n");
 say(cap_name + " barks at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

beg(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You beg for mercy.\n");
 say(cap_name + " begs for mercy.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "pitifully"; }
 tell_object(who, cap_name + "  " + adverb + " begs you.\n");
 write("You beg " + adverb + " " + capitalize(target) + ".\n");
 say(cap_name + " " + adverb + " begs " + capitalize(target) +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You beg " + adverb + ".\n");
 say(cap_name + " begs " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " begs you.\n");
 write("You beg " + capitalize(str) + ".\n");
 say(cap_name + " begs " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


bleed(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("Your wounds bleed alarmingly.\n");
 say(cap_name + "'s wounds bleed alarmingly.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "relentlessly"; }
 tell_object(who, cap_name + " bleeds on you " + adverb + ".\n");
 write("You bleed on " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " bleeds on " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You bleed " + adverb + ".\n");
 say(cap_name + "bleeds " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " bleeds on you.\n");
 write("You bleed on " + capitalize(str) + ".\n");
 say(cap_name + " bleed on " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


blink(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You blink in disbelief.\n");
 say(cap_name + " blinks in disbelief.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "thoughtfully"; }
 tell_object(who, cap_name + " blinks at you " + adverb + ".\n");
 write("You blink at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " blinks at " + capitalize(target) + " " + adverb
+".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You blink " + adverb + ".\n");
 say(cap_name + " blinkss " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " blinkss at you.\n");
 write("You blink at " + capitalize(str) + ".\n");
 say(cap_name + " blinks at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


blush(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You blush to a deep crimson.\n");
 say(cap_name + " blushes to a deep crimson.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "shyly"; }
 tell_object(who, cap_name + " blushes and turns away from you " + adverb + ".\n");
 write("You blush and turn away from " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " blushes and turns away from " + capitalize(target) + " "
 + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You blush " + adverb + ".\n");
 say(cap_name + " blushes " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " blushes and turns away from you.\n");
 write("You blush and turn away from " + capitalize(str) + ".\n");
 say(cap_name + " blushes and turns away from " + capitalize(str) +
 ".\n",who);
    return 1;
                      }  
}

boo(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You let out a 'Boo' of disappointment.\n");
 say(cap_name + " lets out a 'Boo' of disappointment.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "insolently"; }
 tell_object(who, cap_name + " boos at you " + adverb + ".\n");
 write("You boo at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " boos at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You boo " + adverb + ".\n");
 say(cap_name + " boos " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " boos at you.\n");
 write("You boo at " + capitalize(str) + ".\n");
 say(cap_name + " boos at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


bore(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You bore your audience.\n");
 say(cap_name + " is boring.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "immensly"; }
 tell_object(who, cap_name + " bores you " + adverb + ".\n");
 write("You bore " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " bores " + capitalize(target) + " " + adverb
+".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You bore everyone " + adverb + ".\n");
 say(cap_name + " bores everyone " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " bores you.\n");
 write("You bore " + capitalize(str) + ".\n");
 say(cap_name + " bores " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


bored(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You're bored.\n");
 say(cap_name + " is bored.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "immensly"; }
 tell_object(who, cap_name + " seems " + adverb + " bored by you.\n");
 write("You seem " + adverb + " bored by " + capitalize(target) + ".\n");
 say(cap_name + " seems " + adverb + " bored by " + capitalize(target) +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You're " + adverb + " bored.\n");
 say(cap_name + " is " + adverb + " bored.\n");
    return 1;  } else {
 tell_object(who, cap_name + " seems bored by you.\n");
 write("You seem bored by " + capitalize(str) + ".\n");
 say(cap_name + " seems bored by " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


bounce(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You bounce around the room.\n");
 say(cap_name + " bounces around the room.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "happily"; }
 tell_object(who, cap_name + " bounces around you " + adverb + ".\n");
 write("You bounce around " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " bounces around " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You bounce around " + adverb + ".\n");
 say(cap_name + " bounces around " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " bounces around you.\n");
 write("You bounce around " + capitalize(str) + ".\n");
 say(cap_name + " bounce around " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

bow(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You bow to your audience.\n");
 say(cap_name + " bows gracefully.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "gracefully"; }
 tell_object(who, cap_name + " bows before you " + adverb + ".\n");
 write("You bow before " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " bows before " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You bow " + adverb + ".\n");
 say(cap_name + " bows " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " bows before you.\n");
 write("You bow before " + capitalize(str) + ".\n");
 say(cap_name + " bows before " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


burp(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You burp.\n");
 say(cap_name + " burps.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "noisily"; }
 tell_object(who, cap_name + " burps at you " + adverb + ".\n");
 write("You burp at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " burps at " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You burp " + adverb + ".\n");
 say(cap_name + " burps " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " burps at you.\n");
 write("You burp at " + capitalize(str) + ".\n");
 say(cap_name + " burps at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


cackle(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You cackle with an evil look in your eyes.\n");
 say(cap_name + " cackles with en evil look in "+ poss +" eyes.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "evilly"; }
 tell_object(who, cap_name + " cackles at you " + adverb + ".\n");
 write("You cackle at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " cackles at " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You cackle " + adverb + ".\n");
 say(cap_name + " cackles " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " cackles at you.\n");
 write("You cackle at " + capitalize(str) + ".\n");
 say(cap_name + " cackles at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


calculate() {
    if (ghost())
        return 0;
    write("You start calculating pi's decimals...\n");
    say(cap_name + " started calculating pi's decimals once again.\n");
    return 1;
}   


/* The bodypart funcs are a bit bloated :)  -N */ 


caress(str) {
    object who;
    string target, swaptemp;

    if (ghost()) return 0;
    if (!str)  { write("Caress someone, perhaps?\n"); return 1; } 
    bodypart=0; adverb=0;
    if (sscanf(str, "%s %s %s", target, bodypart, adverb))   
       if(target && bodypart && adverb) {
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    swaptemp=adverb;
     if((get_bodypart(bodypart) && (get_adverb(adverb))))
     { adverb=get_adverb(adverb); bodypart=get_bodypart(bodypart); }
     if((get_bodypart(adverb) && (get_adverb(bodypart))))
     { adverb=bodypart; bodypart=swaptemp; }  

    if (!adverb) { if(get_adverb(adverb)) adverb=get_adverb(adverb);
       else if(get_adverb(bodypart)) adverb=get_adverb(bodypart); 
       else adverb = "affectionately"; }
    if (!bodypart) { if(get_bodypart(swaptemp)) bodypart=get_bodypart(swaptemp);
       else if(get_bodypart(bodypart)) bodypart=get_bodypart(bodypart); 
       else bodypart = "head"; }

 /* Up: swap them if in wrong order. Below: return 0 if illegal. */
     if(!(get_bodypart(bodypart) && (get_adverb(adverb)))) return 0;

 tell_object(who, cap_name + " caresses your "+ bodypart +" "+ adverb +
 ".\n");
 write("You caress " + capitalize(target) + "'s " + bodypart +" "+ adverb + 
 ".\n");
 say(cap_name + " caresses " + capitalize(target) + "'s " + bodypart +
 " " + adverb +".\n",who);
    return 1;
                                                }

    if (sscanf(str, "%s %s", target, swaptemp))   {
    adverb=get_adverb(swaptemp);
    bodypart=get_bodypart(swaptemp);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (adverb) {
 tell_object(who, cap_name + " caresses you " + adverb + ".\n");
 write("You caress " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " crosses " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                 } else 
    if(bodypart) {
 tell_object(who, cap_name + " caresses your " + bodypart + ".\n");
 write("You caress " + capitalize(target) + "'s " + bodypart + ".\n");
 say(cap_name + " caress " + capitalize(target) + "'s " + bodypart +
 ".\n",who); 
    return 1;
                  } else return 0;
                                                }
    /* It is either a name or an adverb */
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     return 0;

 tell_object(who, cap_name + " caresses you.\n");
 write("You caress " + capitalize(str) + ".\n");
 say(cap_name + " caresses " + capitalize(str) + ".\n",who);
    return 1;  
}


cheer(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You cheer.\n");
 say(cap_name + " cheers.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "enthousiastically"; }
 tell_object(who, cap_name + " cheers at you " + adverb + ".\n");
 write("You cheer at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " cheers at " + capitalize(target) + " " + adverb + ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You cheer " + adverb + ".\n");
 say(cap_name + " cheers " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " cheers at you.\n");
 write("You cheer at " + capitalize(str) + ".\n");
 say(cap_name + " cheers at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


chuckle(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You chuckle.\n");
 say(cap_name + " chuckles.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "politely"; }
 tell_object(who, cap_name + " chuckles at you " + adverb + ".\n");
 write("You chuckle at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " chuckles at " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You chuckle " + adverb + ".\n");
 say(cap_name + " chuckles " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " chuckles at you.\n");
 write("You chuckle at " + capitalize(str) + ".\n");
 say(cap_name + " chuckles at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


clap(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You clap briefly.\n");
 say(cap_name + " claps briefly.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "briefly"; }
 tell_object(who, cap_name + " claps at you " + adverb + ".\n");
 write("You clap at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " claps at " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You clap " + adverb + ".\n");
 say(cap_name + " claps " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " claps at you.\n");
 write("You clap at " + capitalize(str) + ".\n");
 say(cap_name + " claps at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

click() {
    if (ghost()) 
        return 0;
    write("You start make clicking sound with your tongue.\n");
    say(cap_name + " starts making some weird clicking sounds with " +
    poss + " tongue.\n");
    return 1;
}


comfort(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You try to comfort everyone.\n");
 say(cap_name + " tries to comfort everyone.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "gently"; }
 tell_object(who, cap_name + " comforts you " + adverb + ".\n");
 write("You comfort " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " comforts " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You try to comfort everyone " + adverb + ".\n");
 say(cap_name + " comforts everyone " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " comforts you.\n");
 write("You comfort " + capitalize(str) + ".\n");
 say(cap_name + " comforts " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


confuse(str) {
    object who;
    string target;

    if (ghost()) return 0;
    if(!str) return 0;  

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "completely"; }
 tell_object(who, cap_name + " confuses you " + adverb + ".\n");
 write("You confuse " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " confuses " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) return 0; else {
 tell_object(who, cap_name + " confuses you.\n");
 write("You confuse " + capitalize(str) + ".\n");
 say(cap_name + " confuses " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

confused() {
    if (ghost())
        return 0;
    write("You are confused.\n");
    say(cap_name + " seems confused.\n");
    return 1;
}


congratulate(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You congratulate everyone.\n");
 say(cap_name + " congratulates everyone.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "heartily"; }
 tell_object(who, cap_name + " congratulates you " + adverb + ".\n");
 write("You congratulate " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " congratulates " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You congratulate everyone  " + adverb + ".\n");
 say(cap_name + " congratulates everyone " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " congratulates you.\n");
 write("You congratulate " + capitalize(str) + ".\n");
 say(cap_name + " congratulates " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


cough(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You cough noisily.\n");
 say(cap_name + " coughs noisily.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "noisily"; }
 tell_object(who, cap_name + " coughs at you " + adverb + ".\n");
 write("You cough at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " coughs at " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You cough " + adverb + ".\n");
 say(cap_name + " coughs " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " coughs at you noisily.\n");
 write("You cough at " + capitalize(str) + " noisily.\n");
 say(cap_name + " coughs at " + capitalize(str) + " noisily.\n",who);
    return 1;
                      }  
}


croak(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("Rhiibbit, rhiibbit.\n");
 say(cap_name + " croacks frog-likely.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "weirdly"; }
 tell_object(who, cap_name + " croaks at you " + adverb + ".\n");
 write("You croak at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " croaks at " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You croak " + adverb + ".\n");
 say(cap_name + " croaks " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " croaks at you.\n");
 write("You croak at " + capitalize(str) + ".\n");
 say(cap_name + " croaks at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


cry(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You burst into tears!\n");
 say(cap_name + " bursts into tears!\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "unconsolably"; }
 tell_object(who, cap_name + " cries at you " + adverb + ".\n");
 write("You cry at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " cries at " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You cry " + adverb + ".\n");
 say(cap_name + " cries " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " cries at you.\n");
 write("You cry at " + capitalize(str) + ".\n");
 say(cap_name + " cries at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


cuddle(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You look for someone to cuddle.\n");
 say(cap_name + " looks around for someone to cuddle.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "warmly"; }
 tell_object(who, cap_name + " cuddles you " + adverb + ".\n");
 write("You cuddle " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " cuddles " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You cuddle your teddy " + adverb + ".\n");
 say(cap_name + " cuddles " + poss + " teddy " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " cuddles you like a bear.\n");
 write("You cuddle " + capitalize(str) + " like a bear.\n");
 say(cap_name + " cuddles " + capitalize(str) + " like a bear.\n",who);
    return 1;
                      }  
}


curse(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You curse in disappointment.\n");
 say(cap_name + " curses in disappointment.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "angrily"; }
 tell_object(who, cap_name + " curses at you " + adverb + ".\n");
 write("You curse at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " curses at " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You curse " + adverb + ".\n");
 say(cap_name + " curses " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " curses you to hell.\n");
 write("You curse " + capitalize(str) + " to hell.\n");
 say(cap_name + " curses " + capitalize(str) + " to hell.\n",who);
    return 1;
                      }  
}

dance(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You start dancing. Alright! :)\n");
 say(cap_name + " does the disco-duck.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "merrily"; }
 tell_object(who, cap_name + " dances with you " + adverb + ".\n");
 write("You dance with " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " dances with " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You dance " + adverb + ".\n");
 say(cap_name + " dances " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " sweeps you across the dance floor.\n");
 write("You sweep " + capitalize(str) + " across the dance floor.\n");
 say(cap_name + " sweeps " + capitalize(str) + 
     " across the dance floor.\n",who);
    return 1;
                      }  
}


disagree(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You disagree.\n");
 say(cap_name + " disagrees.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "sternly"; }
 tell_object(who, cap_name + " disagrees with you " + adverb + ".\n");
 write("You disagree with " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " disagrees with " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You disagree " + adverb + ".\n");
 say(cap_name + " disagrees " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " disagrees with you.\n");
 write("You disagree with " + capitalize(str) + ".\n");
 say(cap_name + " disagrees with " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

dreams(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You start daydreaming.\n");
 say(cap_name + " starts daydreaming.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "wishfully"; }
 tell_object(who, cap_name + " dreams about you " + adverb + ".\n");
 write("You dream about " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " dreams about " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You dream " + adverb + ".\n");
 say(cap_name + " dreams " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " dreams about you. Hmm?\n");
 write("You dream about " + capitalize(str) + ". Sigh.\n");
 say(cap_name + " dreams about " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


eep(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You eep.\n");
 say(cap_name + " eeps.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "helplessly"; }
 tell_object(who, cap_name + " eeps at you " + adverb + ".\n");
 write("You eep at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " eeps at " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You eep " + adverb + ".\n");
 say(cap_name + " eeps " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " eeps at you.\n");
 write("You eep at " + capitalize(str) + ".\n");
 say(cap_name + " eeps at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


eww(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You go 'Eww, that's disgusting'.\n");
 say(cap_name + " goes 'Eww, that's disgusting'.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "scornfully"; }
 tell_object(who, cap_name + " goes 'Eww' at you " + adverb + ".\n");
 write("You go 'Eww' at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " goes 'Eww' at " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You go 'Eww' " + adverb + ".\n");
 say(cap_name + " goes 'Eww' " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " goes 'Eww' at you.\n");
 write("You go 'Eww' at " + capitalize(str) + ".\n");
 say(cap_name + " goes 'Eww' at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

excuse(str) {
    object who;
    string target;

    if (ghost()) return 0;
    if(!str) { write("Excuse someone.\n"); return 1; }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "briefly"; }
 tell_object(who, cap_name + " excuses you " + adverb + ".\n");
 write("You excuse " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " excuses " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) return 0; else {
 tell_object(who, cap_name + " excuses you.\n");
 write("You excuse " + capitalize(str) + ".\n");
 say(cap_name + " excuse " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


fart(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You let off a real rip-roarer.\n");
 say(cap_name + " lets off a real rip-roarer.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "hellishly"; }
 tell_object(who, cap_name + " farts at you " + adverb + ".\n");
 write("You fart at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " farts at " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You fart " + adverb + ".\n");
 say(cap_name + " farts " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " farts in your general direction.\n");
 write("You fart in " + capitalize(str) + "'s general direction.\n");
 say(cap_name + " farts in " + capitalize(str) + "'s general direction.\n",who);
    return 1;
                      }  
}


fear(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You shiver in fear.\n");
 say(cap_name + " shivers in fear.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "utterly"; }
 tell_object(who, cap_name + " fears you " + adverb + ".\n");
 write("You fear " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " fears " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You seem " + adverb + " fearful.\n");
 say(cap_name + " seems " + adverb + " fearful.\n");
    return 1;  } else {
 tell_object(who, cap_name + " fears you.\n");
 write("You fear " + capitalize(str) + ".\n");
 say(cap_name + " fears " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


flex(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You flex your tyrannous muscles.\n");
 say(cap_name + " flexes "+ poss +" tyrannous muscles.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "proudly"; }
 tell_object(who, cap_name + " flexes " + poss + " muscles at you " +
 adverb + ".\n");
 write("You flex your muscles at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " flexes " + poss + " muscles at " + capitalize(target) +
 " " + adverb + ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You flex your muscles " + adverb + ".\n");
 say(cap_name + " flexes " + poss + " muscles " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " flexes " + poss + " muscles at you.\n");
 write("You flex your muscles at " + capitalize(str) + ".\n");
 say(cap_name + " flexes " + poss + " muscles at " + capitalize(str) +
".\n",who);
    return 1;
                      }  
}


flip(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You flip head over heels.\n");
 say(cap_name + " flips head over heels.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "neatly"; }
 tell_object(who, cap_name + " flips you " + adverb + 
  " head over heels.\n");
 write("You flip " + capitalize(target) + " " + adverb + 
  " head over heels.\n");
 say(cap_name + " flip " + capitalize(target) + " " + adverb +
  " head over heels.\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You flip head over heels " + adverb + ".\n");
 say(cap_name + " flips head over heels " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " flips you head over heels.\n");
 write("You flip " + capitalize(str) + " head over heels.\n");
 say(cap_name + " flips " + capitalize(str) + " head over heels.\n",who);
    return 1;
                      }  
}

flirt(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You look around for someone to flirt with.\n");
 say(cap_name + " looks for someone to flirt with.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "erotically"; }
 tell_object(who, cap_name + " flirts with you " + adverb + ".\n");
 write("You flirt with " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " flirts with " + capitalize(target) + " " + adverb + 
    ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You " + adverb + " look for someone to flirt with.\n");
 say(cap_name + " " + adverb + " looks for someone to flirt with.\n");
    return 1;  } else {
 tell_object(who, cap_name + " flirts with you.\n");
 write("You flirt with " + capitalize(str) + ".\n");
 say(cap_name + " flirts with " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}



fondle(str) {
    object who;
    string target, swaptemp;

    if (ghost()) return 0;
    if (!str)  { write("Fondle someone, perhaps?\n"); return 1; } 
    bodypart=0; adverb=0;
    if (sscanf(str, "%s %s %s", target, bodypart, adverb))   
       if(target && bodypart && adverb) {
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    swaptemp=adverb;
     if((get_bodypart(bodypart) && (get_adverb(adverb))))
     { adverb=get_adverb(adverb); bodypart=get_bodypart(bodypart); }
     if((get_bodypart(adverb) && (get_adverb(bodypart))))
     { adverb=bodypart; bodypart=swaptemp; }  

    if (!adverb) { if(get_adverb(adverb)) adverb=get_adverb(adverb);
       else if(get_adverb(bodypart)) adverb=get_adverb(bodypart); 
       else adverb = "pervertedly"; }
    if (!bodypart) { if(get_bodypart(swaptemp)) bodypart=get_bodypart(swaptemp);
       else if(get_bodypart(bodypart)) bodypart=get_bodypart(bodypart); 
       else bodypart = "butt"; }

 /* Up: swap them if in wrong order. Below: return 0 if illegal. */
     if(!(get_bodypart(bodypart) && (get_adverb(adverb)))) return 0;

 tell_object(who, cap_name + " fondles your "+ bodypart +" "+ adverb +
 ".\n");
 write("You fondle " + capitalize(target) + "'s " + bodypart +" "+ adverb + 
 ".\n");
 say(cap_name + " fondles " + capitalize(target) + "'s " + bodypart +
 " " + adverb +".\n",who);
    return 1;
                                                }

    if (sscanf(str, "%s %s", target, swaptemp))   {
    adverb=get_adverb(swaptemp);
    bodypart=get_bodypart(swaptemp);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (adverb) {
 tell_object(who, cap_name + " fondles you " + adverb + ".\n");
 write("You fondles " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " fondles " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                 } else 
    if(bodypart) {
 tell_object(who, cap_name + " fondles your " + bodypart + ".\n");
 write("You fondles " + capitalize(target) + "'s " + bodypart + ".\n");
 say(cap_name + " fondles " + capitalize(target) + "'s " + bodypart +
 ".\n",who); 
    return 1;
                  } else return 0;
                                                }
    /* It is either a name or an adverb */
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     return 0;

 tell_object(who, cap_name + " fondles you.\n");
 write("You fondle " + capitalize(str) + ".\n");
 say(cap_name + " fondles " + capitalize(str) + ".\n",who);
    return 1;  
}


foretell() {
    if (ghost())
        return 0;
    write("You try to foretell the future... but fail.\n");
    say(cap_name + " tries to foretell the future... but fails.\n");
    return 1;  
}
        
freeze() {   
    if (ghost())  return 0;       
write("You freeze on your position don't move even a millimeter.\n");
say(cap_name + " freezes on one place without moving even a millimeter.\n");    
    return 1;
}


french(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str) { write("French soneone, perhaps?\n"); return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "passionately"; }
 tell_object(who, cap_name + " kisses you " + adverb + ".\n");
 write("You kiss " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " kisses " + capitalize(target) + " " + adverb + ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {  write("French someone, perhaps?\n"); return 1; }
    else {
 tell_object(who, cap_name + " gives you a long wet kiss.\n");
 write("You give " + capitalize(str) + " a long wet kiss.\n");
 say(cap_name + " gives " + capitalize(str) + " a long wet kiss.\n",who);
    return 1;
                      }  
}


frown(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You frown.\n");
 say(cap_name + " frowns.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "resentfully"; }
 tell_object(who, cap_name + " frowns at you " + adverb + ".\n");
 write("You frown at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " frowns at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You frown " + adverb + ".\n");
 say(cap_name + " frowns " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " frowns at you.\n");
 write("You frown at " + capitalize(str) + ".\n");
 say(cap_name + " frowns at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


gasp(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You gasp in astonishment.\n");
 say(cap_name + " gasps in astonishment.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "thoughtfully"; }
 tell_object(who, cap_name + " gasps at you " + adverb + ".\n");
 write("You gasp at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " gasps at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You gasp " + adverb + ".\n");
 say(cap_name + " gasps " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " gasps at you.\n");
 write("You gasp at " + capitalize(str) + ".\n");
 say(cap_name + " gasps at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

giggle(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You giggle inanely.\n");
 say(cap_name + " giggles inanely.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "inanely"; }
 tell_object(who, cap_name + " giggles at you " + adverb + ".\n");
 write("You giggle at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " giggles at " + capitalize(target) + " " + adverb +
   ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You giggle " + adverb + ".\n");
 say(cap_name + " giggles " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " giggles at you.\n");
 write("You giggle at " + capitalize(str) + ".\n");
 say(cap_name + " giggles at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


gigglesnort(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You gigglesnort wildly.\n");
 say(cap_name + "'s giggling is occasionally interrupted by loud snorts.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "wildly"; }
 tell_object(who, cap_name + " gigglesnorts at you " + adverb + ".\n");
 write("You gigglesnort at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " gigglesnorts at " + capitalize(target) + " " + adverb  +
 ".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You gigglesnort " + adverb + ".\n");
 say(cap_name + " gigglesnorts " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " gigglesnorts at you.\n");
 write("You gigglesnort at " + capitalize(str) + ".\n");
 say(cap_name + " gigglesnorts at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


glare(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You glare into nothingness.\n");
 say(cap_name + " glares into nothingess.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "stonily"; }
 tell_object(who, cap_name + " glares at you " + adverb + ".\n");
 write("You glare at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " glares at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You glare " + adverb + " into nothingness.\n");
 say(cap_name + " glares " + adverb + " into nothingness.\n");
    return 1;  } else {
 tell_object(who, cap_name + " glares at you.\n");
 write("You glare at " + capitalize(str) + ".\n");
 say(cap_name + " glares at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

greet(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You greet everyone.\n");
 say(cap_name + " greets everyone.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "cheerfully"; }
 tell_object(who, cap_name + " greets you " + adverb + ".\n");
 write("You greet " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " greets you " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You greet everyone " + adverb + ".\n");
 say(cap_name + " greets everyone " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " greets you.\n");
 write("You greet " + capitalize(str) + ".\n");
 say(cap_name + " greet " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

glug() {
    if (ghost()) 
        return 0;
    write("You make out some weird sounds with you tongue and throat.\n");
    say(cap_name + "makes out some weird sounds with " + poss + 
    " tongue and throat.\n");
    return 1;
}

grin(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You grin.\n");
 say(cap_name + " grins.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "evilly"; }
 tell_object(who, cap_name + " grins at you " + adverb + ".\n");
 write("You grin at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " grins at " + capitalize(target) + " " + adverb
+".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You grin " + adverb + ".\n");
 say(cap_name + " grins " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " grins at you.\n");
 write("You grin at " + capitalize(str) + ".\n");
 say(cap_name + " grins at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

groan(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You let out a loud groan.\n");
 say(cap_name + " lets out a loud groan.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "loudly"; }
 tell_object(who, cap_name + " groans at you " + adverb + ".\n");
 write("You groan at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " groans at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You groan " + adverb + ".\n");
 say(cap_name + " groans " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " groans at you.\n");
 write("You groan at " + capitalize(str) + ".\n");
 say(cap_name + " groans at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


grope(str) {
    object who;
    string target, swaptemp;

    if (ghost()) return 0;
    if (!str)  { write("Grope someone, perhaps?\n"); return 1; } 
    bodypart=0; adverb=0;
    if (sscanf(str, "%s %s %s", target, bodypart, adverb))   
       if(target && bodypart && adverb) {
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    swaptemp=adverb;
     if((get_bodypart(bodypart) && (get_adverb(adverb))))
     { adverb=get_adverb(adverb); bodypart=get_bodypart(bodypart); }
     if((get_bodypart(adverb) && (get_adverb(bodypart))))
     { adverb=bodypart; bodypart=swaptemp; }  

    if (!adverb) { if(get_adverb(adverb)) adverb=get_adverb(adverb);
       else if(get_adverb(bodypart)) adverb=get_adverb(bodypart); 
       else adverb = "lustfully"; }
    if (!bodypart) { if(get_bodypart(swaptemp)) bodypart=get_bodypart(swaptemp);
       else if(get_bodypart(bodypart)) bodypart=get_bodypart(bodypart); 
       else bodypart = "buttocks"; }

 /* Up: swap them if in wrong order. Below: return 0 if illegal. */
     if(!(get_bodypart(bodypart) && (get_adverb(adverb)))) return 0;

 tell_object(who, cap_name + " gropes your "+ bodypart +" "+ adverb +
 ".\n");
 write("You gropes " + capitalize(target) + "'s " + bodypart +" "+ adverb + 
 ".\n");
 say(cap_name + " gropes " + capitalize(target) + "'s " + bodypart +
 " " + adverb +".\n",who);
    return 1;
                                                }

    if (sscanf(str, "%s %s", target, swaptemp))   {
    adverb=get_adverb(swaptemp);
    bodypart=get_bodypart(swaptemp);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (adverb) {
 tell_object(who, cap_name + " gropes you " + adverb + ".\n");
 write("You gropes " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " gropes " + capitalize(target) + " " + adverb +
 ".\n",who);
    return 1;
                 } else 
    if(bodypart) {
 tell_object(who, cap_name + " gropes your " + bodypart + ".\n");
 write("You gropes " + capitalize(target) + "'s " + bodypart + ".\n");
 say(cap_name + " gropes " + capitalize(target) + "'s " + bodypart +
 ".\n",who); 
    return 1;
                  } else return 0;
                                                }
    /* It is either a name or an adverb */
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     return 0;

 tell_object(who, cap_name + " gropes you.\n");
 write("You grope " + capitalize(str) + ".\n");
 say(cap_name + " gropes " + capitalize(str) + ".\n",who);
    return 1;  
}

growl(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You growl like the beast you are.\n");
 say(cap_name + " growls like a beast.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "fiercely"; }
 tell_object(who, cap_name + " growls at you " + adverb + ".\n");
 write("You growl at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " growls at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You growl " + adverb + ".\n");
 say(cap_name + " growls " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " growls at you.\n");
 write("You growl at " + capitalize(str) + ".\n");
 say(cap_name + " growls at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

grr(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You go 'GRR'.\n");
 say(cap_name + " goes 'GRR'.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "fiercely"; }
 tell_object(who, cap_name + " goes 'GRR' at you " + adverb + ".\n");
 write("You go 'GRR' at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " goes 'GRR' at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You go 'GRR' " + adverb + ".\n");
 say(cap_name + " goes 'GRR' " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " goes 'GRR' at you.\n");
 write("You go 'GRR' at " + capitalize(str) + ".\n");
 say(cap_name + " goes 'GRR' at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

gurgle(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You gurgle toothlessly.\n");
 say(cap_name + " gurgles toothlessly.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "toothlessly"; }
 tell_object(who, cap_name + " gurgles at you " + adverb + ".\n");
 write("You gurgle at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " gurgles at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You gurgle " + adverb + ".\n");
 say(cap_name + " gurgles " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " gurgles at you.\n");
 write("You gurgle at " + capitalize(str) + ".\n");
 say(cap_name + " gurgles at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


hail(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You hail everyone in the room.\n");
 say(cap_name + " hails everyone in the room.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "respectfully"; }
 tell_object(who, cap_name + " hails you " + adverb + ".\n");
 write("You hail " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " hails " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You hail " + adverb + ".\n");
 say(cap_name + " hails " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " hails you.\n");
 write("You hail " + capitalize(str) + ".\n");
 say(cap_name + " hails " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

heh(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You go 'Heh'.\n");
 say(cap_name + " goes 'Heh'.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "cheerfully"; }
 tell_object(who, cap_name + " goes 'Heh' at you " + adverb + ".\n");
 write("You go 'Heh' at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " goes 'Heh' at " + capitalize(target) + " " + adverb
+".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You go 'Heh' " + adverb + ".\n");
 say(cap_name + " goes 'Heh' " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " goes 'Heh' at you.\n");
 write("You go 'Heh' at " + capitalize(str) + ".\n");
 say(cap_name + " goes 'Heh' at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

hiccup(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You hiccup.\n");
 say(cap_name + " hiccups.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "comically"; }
 tell_object(who, cap_name + " hiccups at you " + adverb + ".\n");
 write("You hiccup at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " hiccups at " + capitalize(target) + " " + adverb
+".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You hiccup " + adverb + ".\n");
 say(cap_name + " hiccups " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " hiccups at you.\n");
 write("You hiccup at " + capitalize(str) + ".\n");
 say(cap_name + " hiccups at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

hmm(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You hmm.\n");
 say(cap_name + " hmms.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "thoughtfully"; }
 tell_object(who, cap_name + " hmms at you " + adverb + ".\n");
 write("You hmm at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " hmms at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You hmm " + adverb + ".\n");
 say(cap_name + " hmms " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " hmms at you.\n");
 write("You hmm at " + capitalize(str) + ".\n");
 say(cap_name + " hmms at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

hmpf(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You let out a disappointed hmpf.\n");
 say(cap_name + " lets out a disappointed hmpf.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "disappointedly"; }
 tell_object(who, cap_name + " hmpfs at you " + adverb + ".\n");
 write("You hmpf at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " hmpfs at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You hmpf " + adverb + ".\n");
 say(cap_name + " hmpfs " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " hmpfs at you.\n");
 write("You hmpf at " + capitalize(str) + ".\n");
 say(cap_name + " hmpf at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}


hmph(str) {
    object who;
    string target;

    if (ghost()) return 0;

    if(!str)   {  
 write("You let out an indifferent hmpf.\n");
 say(cap_name + " lets out an indifferent hmpf.\n");
    return 1;  }

    if (sscanf(str, "%s %s", target, adverb))   {
    adverb=get_adverb(adverb);
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player()) return 0;
    if (!adverb) { adverb = "indifferently"; }
 tell_object(who, cap_name + " hmphs at you " + adverb + ".\n");
 write("You hmph at " + capitalize(target) + " " + adverb + ".\n");
 say(cap_name + " hmphs at " + capitalize(target) + " " + adverb +".\n",who);
    return 1;
                                                }
    /* It is either a name or an adverb */
    adverb = get_adverb(str);
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
     if(!adverb) return 0;

    if(adverb) {    
 write("You hmph " + adverb + ".\n");
 say(cap_name + " hmphs " + adverb + ".\n");
    return 1;  } else {
 tell_object(who, cap_name + " hmphs at you.\n");
 write("You hmph at " + capitalize(str) + ".\n");
 say(cap_name + " hmph at " + capitalize(str) + ".\n",who);
    return 1;
                      }  
}

