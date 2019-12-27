CREATE TABLE Alita.Word (
    ID              INT             NOT NULL AUTO_INCREMENT,
    Created         DATETIME        NOT NULL,
    Content         VARCHAR(4000)   CHARACTER SET utf8 COLLATE utf8_unicode_ci,

    CONSTRAINT WORD_ID PRIMARY KEY (ID)    
);