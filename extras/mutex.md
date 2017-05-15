## std::mutex

Conceito utilizado em threads. Essa é a forma para evitar que duas ou mais threads acessem/modifiquem uma determinada variável em uma seção crítica(área de seção compartilhada entre duas threads/processos). Isto é, se a thread 1 quiser acessar um valor A, a thread 2 não pode acessar esse valor ao mesmo tempo. Isso causaria problemas no código e possíveis respostas saíriam diferentes do esperado.
Em suma, mutex seria uma forma de proteção de determinado objeto. Auxília as threads a protegerem sua seção crítica.
Seção crítica seria partes do código que possuem variáveis compartilhadas.

## Exemplo de Uso
```c++
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <map>
#include <string>
 
std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;
 
void save_page(const std::string &url)
{
    // simulate a long page fetch
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "fake content";
 
    g_pages_mutex.lock();
    g_pages[url] = result;
    g_pages_mutex.unlock();
}
 
int main() 
{
    std::thread t1(save_page, "http://foo");
    std::thread t2(save_page, "http://bar");
    t1.join();
    t2.join();
 
    g_pages_mutex.lock();
    for (const auto &pair : g_pages) {
        std::cout << pair.first << " => " << pair.second << '\n';
    }
    g_pages_mutex.unlock();
}
```
Saida:<br>
http://bar => fake content <br>
http://foo => fake content <br>

## Referências:
>[cppreference](http://pt.cppreference.com/w/cpp/thread/mutex)<br>
>[Wikipédia](https://pt.wikipedia.org/wiki/Regi%C3%A3o_cr%C3%ADtica)<br>
