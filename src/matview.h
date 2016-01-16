#ifndef MATVIEW_H
#define MATVIEW_H

#include "common.h"

typedef struct PQLMaterializedView
{
	PQLObject		obj;
	char			*tbspcname;
	bool			populated;

	/* do not load iif view will be dropped */
	char			*viewdef;
	char			*reloptions;
	char			*comment;
	char			*owner;
} PQLMaterializedView;

PQLMaterializedView *getMaterializedViews(PGconn *c, int *n);
void getMaterializedViewAttributes(PGconn *c, PQLMaterializedView *v);
void dumpDropMaterializedView(FILE *output, PQLMaterializedView v);
void dumpCreateMaterializedView(FILE *output, PQLMaterializedView v);
void dumpAlterMaterializedView(FILE *output, PQLMaterializedView a, PQLMaterializedView b);

#endif	/* MATVIEW_H */