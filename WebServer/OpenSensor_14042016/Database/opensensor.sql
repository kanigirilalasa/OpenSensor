/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     4/5/2016 3:17:10 PM                          */
/*==============================================================*/


drop table if exists GAS;

drop table if exists SENSORMODEL;

drop table if exists SENSORVALUE;

/*==============================================================*/
/* Table: GAS                                                   */
/*==============================================================*/
create table GAS
(
   GAS                  varchar(50) not null,
   primary key (GAS)
);

/*==============================================================*/
/* Table: SENSORMODEL                                           */
/*==============================================================*/
create table SENSORMODEL
(
   SENSORMODEL          varchar(50) not null,
   primary key (SENSORMODEL)
);

/*==============================================================*/
/* Table: SENSORVALUE                                           */
/*==============================================================*/
create table SENSORVALUE
(
   SENSORMODEL          varchar(50) not null,
   GAS                  varchar(50) not null,
   TIME                 datetime not null,
   VALUE                float,
   primary key (SENSORMODEL, GAS, TIME)
);

alter table SENSORVALUE add constraint FK_RELATIONSHIP_1 foreign key (SENSORMODEL)
      references SENSORMODEL (SENSORMODEL) on delete restrict on update restrict;

alter table SENSORVALUE add constraint FK_RELATIONSHIP_2 foreign key (GAS)
      references GAS (GAS) on delete restrict on update restrict;

