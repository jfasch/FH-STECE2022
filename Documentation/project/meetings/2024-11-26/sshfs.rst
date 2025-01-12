.. include:: <mmlalias.txt>


Development Process
===================

.. sidebar:: See also

   * :doc:`jfasch:trainings/material/soup/linux/ssh/sshfs`


Starting A Feature : Forking On Github
--------------------------------------

* Where do I start from? |longrightarrow| most recent version of
  https://github.com/jfasch/FH-STECE2022
* Not necessarily
* Fork On Github

Getting Fork's Source
---------------------

Via SSH (have to deploy SSH public key on your Github account)

.. code-block:: console

   $ cd ~/My-Projects
   $ git clone git@github.com:FH-ECE22/FH-STECE2022.git

Development: *pc native*
------------------------

Follow :doc:`/development/build` for how to get to a *pc native* build

* Build on PC

Development: *pc cross*
-----------------------

* Setup cross toolchain, including CMake toolchain file,
  :doc:`jfasch:trainings/material/soup/linux/toolchain/raspberry-pi/toolchain-setup`.

.. code-block:: console

   $ ls -l ~/x-tools/armv8-rpi4-linux-gnueabihf.cmake 
   -rw-r--r--. 1 jfasch jfasch 1011 Oct  8 09:33 /home/jfasch/x-tools/armv8-rpi4-linux-gnueabihf.cmake

.. code-block:: console

   $ mkdir ~/My-Builds/FH-STECE2022
   $ cd ~/My-Builds/FH-STECE2022-raspi

.. code-block:: console

   $ cmake -DCMAKE_TOOLCHAIN_FILE=/home/jfasch/x-tools/armv8-rpi4-linux-gnueabihf.cmake ~/My-Projects/FH-STECE2022/
   $ make -j8

Development: *target native*
----------------------------

When cross compilation fails, need to build on the target

* build on pi (native pi)

  * work on pi, and git clone on the pi. over ssh which I recommed.

    why not HTTPS? Although github desktop works, it works with github
    only, and in the future we don't want to have to admit that::

      We can not move our company's intellectual property to `Gitlab
      <https://about.gitlab.com>`__ because we do not trust Microsoft
      (owner of Github), or even set up our own instance of it because
      we don't trust anybody) ...

      **Because the cost of the move would ruin the company**

      * Rewrite all the processes that we built around Github features 
      * Train all developers (developers whine too)

    Github desktop is just the beginning (people have `always felt
    <https://www.jesus.ch/themen/glaube/andachten/leben_ist_mehr/102586-wehret_den_anfaengen.html>`__
    that dependencies are bad) of a `lock-in
    <https://de.wikipedia.org/wiki/Lock-in-Effekt>`__. Depending on
    how large the amount of unawareness in a company is, such a move
    would or would not ruin the company.




    for example
  
    * when sshd is started, reachable on the internet as pi/raspberry,
      or nowadays over an explicitly created user) BY ANY ATTACKER ON
      ANY MACHINE IN THE LOCAL NET
    * grafana server 

      * runs as myself. you can start it at boot as some regular
	restricted service user, but during development this is not
	convenient.
      * opens an unencrypted network port on ``0.0.0.0``

	reachable BY ANY ATTACKER ON ANY MACHINE IN THE LOCAL NET. bad
	if the grafana server has bugs. it is written in a memory safe
	languages (no C), so many kinds of bugs are simply not
	there. but who guarantees me that is can't be tricked into
	serving me (err, the attacker), ``~/.ssh/id_rsa``.

  

* leave credentials on PC, and sshfs-mount remote on local

  * suppose you have an account on the target machine
  
    show interactive login
  
  * you can mount, e.g the target home directory.
  
    show mount
  
  * umount
  
    * fusermount
    * umount as user
  
  * advantage of doing this
  
    * private key stays in your local safe
    * can use local tools, 
  
  	* short term deployment, editing remote unit files in my IDE
  	  (emacs) and restarting interactively over ssh
  	* checking out a repo onto target machine, with git running
  	  locally
  	* using it vc, for example, or emacs. show both - or me,
  	  programming in two repos.
  
  	* qemu tricks in the build process, 
  
  	  * as a self-signing method?! :-)) image is executed to
  	    generate a key from the build hardware, and build logs in
  	    over ssh (because ssh keys got deployed *during the
  	    build*) -> retrieves the cert private that was created,
  	    which is the permission to log into a target machine that
  	    has this cert
  	  * taking a snapshot of things of interest, say modified
  	    config files to get a running system
