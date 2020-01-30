#define TPO this_player()->query_objective()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define TPR this_player()->query_pronoun()

inherit "obj/armour";
int i;
string hype;

short() {
  switch(i) {
  case 0 : hype = "Maybe you should do something to this poor little sculpture?";
           return "A strange sculpture"; break;

  case 1 : hype = "You might be able to do something more to this sculpture.";
           return "An ordinary-looking sculpture"; break;

  case 2 : hype = "The sculpture seems to have an awkward expression on its\n"+
                  "face. Maybe you could help it out somehow?";
           return "A fairly familiar-looking sculpture"; break;

  case 3 : hype = "It seems that this sculpture is somehow playing with your\n"+
                  "expense. You can picture it pulling a huge grin on its face and\n"+
                  "laughing at you. You are quite sure you can do something more.\n";
           return "A familiar-looking sculpture"; break;

  case 4 : hype = "The sculpture makes you feel pitiful. And, somehow, you\n"+
                  "seem to enjoy that feeling. You feel like doing something more.\n";
           return "A very familiar-looking sculpture"; break;

  case 5 : hype = "The sculpture seems to own you. You are getting somewhat\n"+
                  "irritated looking at it.\n";
           return "A sculpture resembling someone close to you"; break;

  case 6 : hype = "A trickle of slime is running down the sculpture's cheek,\n"+
                  "making this work of art look pitiful and weak. You will definitely\n"+
                  "have to do something more here.\n";
           return "A sculpture resembling someone close to you(very weak)"; break;

  case 7 : hype = "The sculpture is naked, though you would rather see it with\n"+
                  "some clothes on. You feel a bit sorry for the sculpture. Something\n"+
                  "more has to be done here. You are sure of it.\n";
           return "A naked sculpture resembling someone close to you(very weak)"; break;

  case 8 : hype = "The naked sculpture looks amazingly ugly. You wonder what\n"+
                  "what the creator of this sculpture tried to accomplish by making the\n"+
                  "statue as ugly as it is. Or maybe the creator did its best, but the\n"+
                  "model for the art piece was just unearthily bad-looking. You are one\n"+
                  "step away from solving the mystery of the sculpture. Go for it!!\n";
           return "A naked sculpture resembling someone very close to you(very weak)(ugly)"; break;

  case 9 : 
           return "A naked sculpture of "+TPN+"(very weak)(ugly)"; break;
  }
}

long(str) {
  if(i<7) write(short()+" is standing here.\n");
  if(i>6) write(short()+"\n"+"is standing here.\n");
  write("It seems to portray someone but you have no idea who that person might\n");
  write("be. The sculpture is made of white marble and its surface seems to be\n");
  write("very smooth. "+hype+"\n");
  if(i==9) {
  write("You burst into laughter when you see this pitiful-looking statue of\n");
  write("yourself. Though you feel honored that someone has spent a lot of\n");
  write("time and trouble to create this sculpture perfectly resembling you,\n");
  write("you feel that in overall the statue seems to lack the respect it\n");
  write("should bear. Somewhere in the back of your mind you can't but wonder\n");
  write("if someone has been pulling your leg big time. As you examine the\n");
  write("statue more closely, you notice that it is showing its middle finger\n");
  write("to you and it has an enormous grin on its face. There seems to be a\n");
  write("small engraving in the pedestal the sculpture is standing on.\n");
  write("The text says:\n");
  write(this_player()->query_name()+
        ", you're just a pitiful mortal so shut up, stop whining and live with it!\n");
  call_out("finger1", 3);
  call_out("finger2", 6);
  call_out("finger3", 9);
  call_out("loppu", 12);
  }
  return;
}

/*long(str) {
    write("You burst into laughter when you see this pitiful-looking statue of\n");
    write("yourself. Though you feel honored that someone has spent a lot of\n");
    write("time and trouble to create this sculpture perfectly resembling you,\n");
    write("you feel that in overall the statue seems to lack the respect it\n");
    write("should bear. Somewhere in the back of your mind you can't but wonder\n");
    write("if someone has been pulling your leg big time. As you examine the\n");
    write("statue more closely, you notice that it is showing its middle finger\n");
    write("to you and it has an enormous grin on its face. There seems to be a\n");
    write("small engraving in the pedestal the sculpture is standing on.\n");
    write("The text says:\n");
    write(this_player()->query_name()+
          ", you're just a pitiful mortal so shut up, stop whining and live with it!\n");
    call_out("finger1", 3);
    call_out("finger2", 6);
    call_out("finger3", 9);
    call_out("loppu", 12);
  return;
}*/

finger1() {
  write("[fingered by: A naked sculpture of "+TPN+"]\n");
}

finger2() {
  write("[fingered by: Ahma]\n");  

}

finger3() {
  write("[fingered by: Duncan]\n");
}

loppu() {
  write("Have a nice day.\n");
}

id(str) { return str == "sculpture" ; }

get(str) { return 0; }

init() {
  ::init();
  add_action("turn", "rotate");
  add_action("turn", "turn");
  add_action("push", "push");
  add_action("pull", "pull");
  add_action("kick", "kick");
  add_action("touch", "touch"); 
  add_action("spit", "spit");
  add_action("caress", "caress");
  add_action("hug", "hug");
  add_action("kiss", "kiss");
}


turn(str) {
    if(str != "sculpture") return;
    if(i != 0) return;
    write("You turn the sculpture around and it begins to resemble something familiar.\n");
    say(TPN+" turns the sculpture around.\n");
    i = 1;
    short();
    init();
    return 1;
}

push(str) {
    if(str != "sculpture") return;
    if(i != 1) return;
    write("You push the sculpture back a bit to observer it better in whole.\n");
    write("You really think you have seen this person somewhere before.\n");
    say(TPN+" pushes the sculpture to observe it better.\n");
    i = 2;
    short();
    init();
    return 1;
}

pull(str) {
    if(str != "sculpture") return;
    if(i != 2) return;
    write("You can't think up anything else, so you pull the sculpture's index finger.\n");
    write("... The sculpture lets out a gentle fart.\n");
    write("You think the sculpture looks even more familiar now.\n");
    say(TPN+" pulls the sculpture's finger and a gentle fart can be heard.\n");
    i = 3;
    short();
    init();
    return 1;
}

kick(str) {
    if(str != "sculpture") return;
    if(i != 3) return;
    write("You feel frustrated and kick the sculpture.\n");
    write("OUCH! A huge lightning hits you from the sky.\n");
    this_player()->hit_with_spell(1000);
    write("The pain makes you notice some new familiar features in the sculpture.\n");
    say(TPN+" kicks the sculpture and a huge lightning hits "+TPO+" from the sky.\n");
    i = 4;
    short();
    init();
    return 1;
}

touch(str) {
    if(str != "sculpture") return;
    if(i != 4) return;
    write("You are feeling a bit masochistic and touch the sculpture's smooth surface.\n");
    write("Huge flames shoot out from the statue burning you badly.\n");
    this_player()->hit_with_spell(1500);
    write("The pain makes you notice even more familiar details about the sculpture.\n");
    write("The sculpture resembles someone who is very close to you.\n");
    say(TPN+" touches the sculpture and is burnt badly by the magical flames.\n");
    i = 5;
    short();
    init();
    return 1;
}

spit(str) {
    int randomi;
    if(str != "sculpture") return;
    if(i != 5) return;
    randomi = random(10);
    if(randomi > 6) {
      write("You try to spit at the sculpture for no reason.\n");
      write("But you only manage drool all around your face. Truly a pathetic attempt.\n");
      say(TPN+" tries to spit at the sculpture but manages only to drool around "+TPP+" face.\n");
      return 1;
    }
    if(randomi > 4) {
      write("You spit at the sculpture for no reason.\n");
      write("... You miss!\n");
      say(TPN+" spits at the sculpture but misses.\n");
      return 1;
    }
    if(randomi > 0) {
    write("You spit at the sculpture for no reason.\n");
    write("... And you didn't miss!\n");
    write("... But a magical force bounces your spit back into your face. YUCK!\n");
    say(TPN+" spits at the sculpture but a magical force bounces the slime back into "+TPP+" face.\n");
    return 1;
    }
    write("You spit at the sculpture for no reason.\n");
    write("... And hit!\n");
    write("Nothing happens. As expected.\n");
    write("... But the descriptions seem to change.\n");
    say(TPN+" spits on the sculpture but nothing happens.\n");
    i = 6;
    short();
    init();
    return 1;
}

caress(str) {
    if(str != "sculpture") return;
    if(i != 6) return;
    write("You feel very lonely inside and finally surrender to your lusty desires.\n");
    write("You start to caress the sculpture forcefully, leaving it no change to fight back.\n");
    write("Then, suddenly, you realize what you are doing and stop it. You blush a little.\n");
    write("You horny little you! You really can't control yourself, huh? Get a life!\n");
    write("... You notice that the sculpture seems to be naked.\n");
    say(TPN+" lustfully caresses the sculpture. "+capitalize(TPR)+" seems very horny and stupid\n");
    say("when doing it. Suddenly "+TPN+" stops "+TPP+" freaky action.\n");
    i = 7;
    short();
    init();
    return 1;
}

hug(str) {
    if(str != "sculpture") return;
    if(i != 7) return;
    write("You decide to hug the sculpture. You press yourself against the sculpture's\n");
    write("smooth surface. But despite of its smoothness, you finally notice how ugly\n");
    write("the sculpture is and let go. You would never want to be someone as pitiful-\n");
    write("looking as this statue's model.\n");
    say(TPN+" hugs the statue. After a while "+TPR+" notices how ugly the sculpture\n");
    say("actually is and moves few steps back.\n");
    i = 8;
    short();
    init();
    return 1;
}

kiss(str) {
    if(str != "sculpture") return;
    if(i != 8) return;
    write("You sigh in frustration and disgust for the sculpture but decide to push\n");
    write("yourself over the edge once more. You gather all your might and go for it.\n");
    write("You give the naked, ugly sculpture a deep kiss.\n");
    this_player()->hit_with_spell(500);
    write("Your brain is about to melt as you suddenly realize who the sculpture is\n");
    write("representing.\n");
    write("... And that is, yourself. Naked. And ugly.\n");
    write("You sense an urgent anxiety floating around you.\n");
    say(TPN+" gives the statue a deep kiss. Suddenly "+TPR+" steps a few steps back in\n");
    say("shock as "+TPR+" realizes that the naked sculpture is actually representing you!\n");
    i = 9;
    short();
    init();
    return 1;
}