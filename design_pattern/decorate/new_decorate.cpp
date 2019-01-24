#include <stdio.h>

class CStream
{
public:
  virtual int read() = 0;
  virtual int write() = 0;
  virtual int set(char *oBuf){}
  virtual char *get() {
    return this->m_szBuf;
  }
  CStream(){
    sprintf (m_szBuf, "__line__");
  }
  
protected:
  char m_szBuf[256];
};

class CFileStream : public CStream
{
public:
  virtual int read() {
    sprintf (this->m_szBuf, "%s", "CFileStream read:__line__\n");
  }
  virtual int write() {
    printf ("CFileStream write\n");
  }
};

class CNetStream : public CStream
{
public:
  virtual int read() {
    sprintf (this->m_szBuf, "%s", "CNetStream read:__line__\n");
  }
  virtual int write() {
    printf ("CNetStream write\n");
  }
  virtual int set(char *pBuf) {
    sprintf (this->m_szBuf, "%s", pBuf);
  }
};

class CMemStream : public CStream
{
public:
  virtual int read() {
    sprintf (this->m_szBuf, "%s", "CMemStream read:__line__\n");
  }
  virtual int write() {
    printf ("CMemStream write\n");
  }
};

class CDecorateStream : public CStream
{
public:
  CDecorateStream(CStream *stream) {
    this->m_pStream = stream;
  }

protected:
  CStream *m_pStream;
};

class CCryptoStream : public CDecorateStream
{
public:
  CCryptoStream(CStream *stream) : CDecorateStream (stream) {}
  virtual int read() {
    //printf ("debug read 1:%s\n", this->m_pStream->get ());
    this->m_pStream->read ();
    //printf ("debug read 2:%s\n", this->m_pStream->get ());
    sprintf (this->m_szBuf, "CCryptoStream__%s\n", this->m_pStream->get ());
    //this->m_pStream->set (this->m_szBuf);
    //printf ("debug read 3:%s\n", this->m_pStream->get ());
  }
  // write function must exist
  virtual int write() {
    printf ("CCryptoStream write\n");
  }
};

int main()
{
  CStream *stream = new CNetStream();
  stream->read ();
  printf ("stream you get:%s\n", stream->get ());
  
  CCryptoStream *cs = new CCryptoStream (stream);
  cs->read ();
  
  printf ("stream you get:%s\n", stream->get ());
  printf ("cs you get:%s\n", cs->get ());

  return 0;
}