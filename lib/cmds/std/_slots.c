status cmd_slots() {
   mapping slots;
   string *slotcheck;
   string *output;
   int i;
   object *eqs;
   eqs = all_inventory(this_player());
   slots = ([ ]);
   slotcheck = ({ "torso", "left finger", "right finger", "head", "feet", "legs",
                  "belt", "neck", "cloak", "hands", "arms", });
   for(i=0;i<sizeof(eqs);i++) {
      if(eqs[i]->query_worn()) {
        if(eqs[i]->query_slot() == "finger" && !slots["left finger"])
          slots += ([ "left finger":(eqs[i]->short()), ]);
        else if(eqs[i]->query_slot() == "finger" && slots["left finger"])
          slots += ([ "right finger":(eqs[i]->short()), ]);
        else
          slots += ([ (eqs[i]->query_slot()):(eqs[i]->short()), ]);
      }
   }
   for(i=0;i<sizeof(slotcheck);i++) if(!slots[slotcheck[i]])
      slots += ([ slotcheck[i]:"Empty", ]);
   
   output = m_indices(slots);
   for(i=0;i<sizeof(output);i++)
      write(capitalize(output[i])+": "+slots[output[i]]+"\n");
   return 1;
}
