<img width="512" alt="ascii-art-image" src="https://github.com/user-attachments/assets/84338c7e-9b43-4289-a98f-b360147b055c" />

# Keeping Coding

This project has the goal to pursue the introduction to the C programming language and other well-used languages, including various resources, links to exercise yourself, and a few projects to complete alone or in groups.

## Ressources

### Reading recommendation

- *The C Programming Language* (K&R), 2nd edition
- *The C++ Programming Language* (Stroustrup), 4th edition
- *Introduction to Algorithms* (CLRS), 3rd edition

(Easily findable on internet)

### Useful links

To read and exercise :
- A link to the [42 Piscine from 2022](https://github.com/BennieBickles/Piscine-42)
- The [Git documentation](https://git-scm.com/docs)
- [Learn C](https://learn-c.org/)
- [C++ Reference](https://cppreference.com/)
- [OpenClassrooms](https://openclassrooms.com/en/), [FR](https://openclassrooms.com/fr/)
- [Exercism](https://exercism.org)
- [CodinGame](https://codingame.com)

## Presentation

The project is contain multiple module to work and learn different topics, each `0x-language-name-of-module` folder is a module and each module has a list of exercise in folders name as `0x-name-of-exercise`. All modules and exercises within the modules are rated on the dificulty and time between ⭐ and ⭐⭐⭐. Exercises difficulty is proportional to the module difficulty, a ⭐⭐⭐ exercise in a ⭐ module is easier than a ⭐⭐⭐ exercise in a ⭐⭐⭐ module. Module are not meant to be completed in order.

Here is a list of the current modules () :

| Module | Name | Level |
| :---: | :---: | :---: |
| Module 00 | [C Re Introduction](00-c-re-introduction) | ⭐ |
| Module 01 | [C Input/Output Games](01-c-io-games)     | ⭐ |
| Module 02 | [C Intermediate](02-c-intermediate)       | ⭐⭐ |
| Module 03 | [C Advanced](03-c-advanced)               | ⭐⭐⭐ |
| Module 04 | [Work your Logic](04-work-your-logic)     | ⭐ |

## Work Environment

You can work in any environment that can write, compile and run C code.
The recommended environment is to keep working on Linux and use a more advanced IDE than Vim. (e.g. Visual Studio Code, CLion, Eclipse, etc.)
You will need to install a C compiler (e.g. GCC) and a debugger optionally (e.g. GDB) to compile and run your code.
Your work validation will run on Linux, be sure that your code is compatible. (e.g. `unistd.h` is UNIX only)

## How to ... ?

### How to start ?

**1/** Create your own *fork* of this repository [here](https://github.com/quinquinet/Keeping-Coding/fork) (up-right button) and clone it to your local machine using :
```
git clone https://github.com/<username>/Keeping-Coding.git
```
You now have a copy of this repository on your GitHub account and on your local machine.

**2/** In the cloned repository, put the original repository as a upstream remote to be able to pull the latest changes from the original repository.
```
git remote add upstream https://github.com/quinquinet/Keeping-Coding.git
```
You should have something like this :
```
$ git remote -v
origin https://github.com/<username>/Keeping-Coding.git
upstream https://github.com/quinquinet/Keeping-Coding.git
```

**3/** To update any change from the original to your forked repository, you can run the following commands :
```
git fetch upstream
git merge upstream/main
git push origin main        # Push can be done later
```
**Don't forget to check for new updates.**

### How to work ?

**4/** Each exercise has already a empty `work` folder where you can work in it. You can create the required files in this folder to complete the exercise. **DON'T DELETE OR MODIFY ANY OTHER FILES OUTSIDE OF THE `work` FOLDERS**. Although you can read the structure files and try to understand how everything works.

**5/** Once you have completed an exercise, you can test it by running `check.sh` (each exercise has one) or compile and test it yourself. You can add your own test in the `testing` folder. Please report any testing issue.

### How to validate ?

**6/** When you are satisfied with your work, you can commit your changes and push them to your forked repository.

**7/** You can then go in the [Actions tab](https://github.com/quinquinet/Keeping-Coding/actions), here find the `Automatic check` workflow and click on `Run workflow`. The workflow will automatically compile, run, and test each exercise and validated your work.

**8/** After validation, you can create a new **Pull Request** to show your work, or if any have any question/issue.

You can also find a `solution` for each exercise, look at it only when you have validated the exercise to compare your work. If you are stuck, **ask someone**.

### How to get some help ?

There is a special place for discussion, [here](https://github.com/quinquinet/Keeping-Coding/discussions/categories/need-help) you can create a new discussion and ask for some help on your exercise.

### How to report a bug, an issue ?

Go to [Issue](https://github.com/quinquinet/Keeping-Coding/issues), create a **New issue**, select your issue category, fill the form and it's done !

### How to contribute ?

You have two way to contribute to this project :
- **Become a collaborator**, create a [issue]() and ask to become a collaborator, or ask personally if you know a collaborator to this project.
- If you want to contribute only **occasionally**, you can create issues and suggest new exercises and modules through [issue](https://github.com/quinquinet/Keeping-Coding/issues) or [pull request](https://github.com/quinquinet/Keeping-Coding/pulls). 

## Discussion

This repository has discussion channels open to everyone, those channels are lightly moderated, please be polite.
Please keep all discussion in the correct category.
Check updates, new exercises and new modules [here](https://github.com/quinquinet/Keeping-Coding/discussions/categories/announcements).

## Advices

This project is designed to help you learn and improve your coding skills, but also to keepd you practicing and giving you the good use and foundation to work in collaborative projects. Here are some advices to help you succeed:
- **READ** the instructions carefully before starting to code. This a kind of job where you will need to do your own research and find the right solutions to the problems you will face. The instructions will give you a good idea of what is expected from you. Get use to reading documentations and searching for information online. Even outside of this project, it is not called `README` for nothing.
- **PLAN** your work before starting to code. Take the time to understand the problem and think about the best way to solve it.
- **TEST** your code frequently. Don't wait until the end to test your code. Test it as you go, and make sure it works as expected.
- Solution are accessible, but you should try to solve the exercises by yourself before looking at them. The goal is to learn and improve your skills, not just to get the right answer. If you are stuck, ask someone for help.
- This project **must not** be your only source of learning. You can learn from other similar and more advanced projects.
- Keep a regular rythm, even if you work couple hours a week, **DON'T HAVE LONG BREAKS** (over weeks or months). You will lose your progress and your motivation, even 5 minutes to review a code is good to keep going.
- Don't force yourself to work on projects you are tired of or you don't like. Try to find what you like and what you want to learn, this project is very incomplete and only review a small part of what programming really is. You can always come back to the project later.
- This project is **completely open** so even if you don't actively contribute to this project, I sugjest that you have a look at the structure of the project (workflows, scripts, tests, ..), you can learn a lot from it and give you ideas of what you can do on our own.

## Collaboration

**Doing is the best way to learn !**

This project is open to collaboration and contributions **to anyone**. If you have any suggestions, improvements, or want to contribute with new exercises or resources, feel free to open an issue or submit a pull request. Not that is project is not a professional project, the structure might not be idle and the exercises might not be perfect or the best way to learn, it is meant to continue your introduction to programming by keeping coding.
