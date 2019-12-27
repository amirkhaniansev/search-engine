CREATE TABLE Alita.Cache (
    ID              INT             NOT NULL AUTO_INCREMENT,
    Created         DATETIME        NOT NULL,
    Modified        DATETIME        NOT NULL,
    ProcessState    TINYINT         NOT NULL,
    Link            VARCHAR(4000)   CHARACTER SET utf8 COLLATE utf8_unicode_ci,
    Content         VARCHAR(4000)   CHARACTER SET utf8 COLLATE utf8_unicode_ci,

    CONSTRAINT PK_CACHE_ID    PRIMARY KEY (ID)
);