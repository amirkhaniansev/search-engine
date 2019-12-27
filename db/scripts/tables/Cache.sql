CREATE TABLE Alita.Cache (
    ID              INT             NOT NULL AUTO_INCREMENT,
    Created         DATETIME        NOT NULL,
    Modified        DATETIME        NOT NULL,
    ProcessState    TINYINT         NOT NULL,
    Link            VARCHAR(4000)   CHARSET utf8,
    Content         VARCHAR(4000)   CHARSET utf8,

    CONSTRAINT PK_CACHE_ID    PRIMARY KEY (ID)
);