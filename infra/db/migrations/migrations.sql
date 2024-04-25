CREATE TABLE public.brands (
	id integer NOT NULL,
	"name" varchar NULL,
	CONSTRAINT brands_pk PRIMARY KEY (id)
);

CREATE TABLE public.items (
	id integer NOT NULL,
	"name" varchar NULL,
	CONSTRAINT brands_pk PRIMARY KEY (id)
    "brand" integer NOT NULL;
);
ALTER TABLE public.items ADD CONSTRAINT items_brands_fk FOREIGN KEY (brand) REFERENCES public.brands(id);
