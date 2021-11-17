#ifndef MOBITA_H
#define MOBITA_H

#include "boolean.h"
#include "engine.h"
#include "listbuilding.h"
#include "point.h"
#include "tas.h"
#include "todolist.h"

typedef struct {
  Building Posisi;
  int Uang;
  int Speed;
  int speedBoost;
  int incCapacity;
  int returnToSender;
} MOBITA;

#define Posisi(P) (P).Posisi
#define Uang(P) (P).Uang
#define Speed(P) (P).Speed
#define speedBoost(P) (P).speedBoost
#define incCapacity(P) (P).incCapacity
#define returnToSender(P) (P).returnToSender

void CreateMobita(MOBITA *MOB, Building HQ);
/*Membentuk mobita dengan posisi di headquarters dan uang = 0*/
/*I.S. MOB sudah terdefinisi*/
/*F.S. Terbentuk mobita sesuai definisi diatas*/

void move(MOBITA *MOB, Building dest);
/*Memindahkan mobita ke posisi dest dan menambah waktu sesuai item dan ability
 * yang dimiliki*/
/*I.S. MOB terdefinisi dan dest ada di listbuilding*/
/*F.S. Posisi MOB berubah jadi dest dan waktu bertambah sesuai item dan ability
 * yang dimiliki*/

void addAbility(MOBITA *MOB, char s);

void removeAbility(MOBITA *MOB, char s);

void mobitaReturn(MOBITA MOB, Tas *t, Todolist *td, InprogressList *ip);

void changeSpeed(MOBITA *MOB, int val);

void changeMoney(MOBITA *MOB, float money);

#endif